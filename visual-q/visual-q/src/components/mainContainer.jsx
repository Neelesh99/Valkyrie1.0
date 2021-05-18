import React from "react"
import "./mainContainer.css"
import Form from 'react-bootstrap/Form'
import Button from 'react-bootstrap/Button'
import Table from 'react-bootstrap/Table'
import ToggleButtonGroup from 'react-bootstrap/ToggleButtonGroup'
import ToggleButton from 'react-bootstrap/ToggleButton'

const electron = window.require('electron');
const ipcRenderer = electron.ipcRenderer;



async function sendFile(val){
    const res = await ipcRenderer.sendSync('sendFile', val);
    console.log(res);
    return res;
}

async function getLastFile(){
    const res = await ipcRenderer.sendSync('fetchLast', 0);
    return res;
}

class MainContainer extends React.Component{

    constructor(props){
        super(props);
        this.state = {value: '', result: '', execMode: 'c'};
        this.handleSubmit = this.handleSubmit.bind(this);
        this.handleChange = this.handleChange.bind(this);
        this.renderOutput = this.renderOutput.bind(this);
        this.handleExecutionModeSwitch = this.handleExecutionModeSwitch.bind(this);
        this.getButtonVariant = this.getButtonVariant.bind(this);
        this.getBackGround = this.getBackGround.bind(this);
        this.handleFirstMount = this.handleFirstMount.bind(this);
    }

    componentDidMount(){
        this.handleFirstMount();
    }

    async handleFirstMount(){
        try {
            var res = await getLastFile();
            console.log(res);
            this.setState({value: res, result: this.state.result, execMode: this.state.execMode});
        } catch(e){
            console.log("Error opening last saved output.qasm");
        }
    }

    async handleSubmit(event){
        const fileName = "output.qasm";
        console.log(this.state.execMode);
        const val = [fileName, this.state.value, this.state.execMode];
        try{
            var res = await sendFile(val);
            this.setState({value: this.state.value, result: res, execMode: this.state.execMode});
        }
        catch(e){
            console.log("Error during valkyrie run")
        }
        return false;
    }

    handleChange(event){
        this.setState({value: event.target.value, result: this.state.result, execMode: this.state.execMode});
    }

    handleExecutionModeSwitch(event){
        if(event === 1){
            this.setState({value: this.state.value, result: this.state.result, execMode: 'c'});
        } else {
            this.setState({value: this.state.value, result: this.state.result, execMode: 'g'});
        }
    }

    getButtonVariant(){
        if(this.state.execMode === 'g'){
            return "success"
        } else{
            return "primary"
        }
    }

    getBackGround(){
        if(this.state.execMode === 'g'){
            return "mainContent-gpu"
        } else{
            return "mainContent"
        }
    }
    
    render(){
        return (<div className={this.getBackGround()}>
            <div className="write-code">
                Hello there, please enter your QASM code below:
            </div>
            <div>
            <ToggleButtonGroup type="radio" name="options" defaultValue={1} onChange={this.handleExecutionModeSwitch}>
                <ToggleButton variant={this.getButtonVariant()} value={1}>CPU Execution Mode</ToggleButton>
                <ToggleButton variant={this.getButtonVariant()} value={2}>GPU Execution Mode</ToggleButton>
            </ToggleButtonGroup>
            </div>
            <div>
                <Form>
                    <Form.Group controlId="qasmInput">
                        <Form.Label>QASM Input</Form.Label>
                        <Form.Control 
                            as="textarea"
                            rows={10}
                            placeholder="OPENQASM 2.0;"
                            defaultValue={this.state.value}
                            onChange={this.handleChange}
                        />
                    </Form.Group>
                    <Button variant="primary" type="button" onClick={this.handleSubmit}>
                        Submit
                    </Button>
                </Form>
                <br/>
                {this.renderOutput()}
            </div>
        </div>)
    }

    evaluateRow(cState){
        var name = cState["id"];
        var values = cState["values"];
        return (values.map((val, index) => (
            <tr>
                <td>
                    {name}
                </td>
                <td>
                    {index}
                </td>
                <td>
                    {val}
                </td>
            </tr>
        )))
    }

    handleIndex(index, svLength){
        var str = index.toString(2);
        const noElem = Math.log2(svLength);
        console.log(noElem - str.length);
        const len = str.length;
        for(var i = 0; i < noElem - len; i++){
            str = "0" + str;
        }
        return str;
    }

    renderOutput(){
        if(this.state.result === ''){
            return <div>Please click submit to see output</div>
        } else {
            var obj = JSON.parse(this.state.result);
            var StateVector = obj["StateVector"];
            var svLength = StateVector.length;
            var ClassicalRegisters = obj["ClassicalRegisters"];
            console.log(StateVector);
            console.log(ClassicalRegisters);
            return <div>
                Output:
                <br/>
                <Table striped bordered hover>
                        <thead>
                            <tr>
                                <th>Classical Register</th>
                                <th>Index</th>
                                <th>Measured Value</th>
                            </tr>
                        </thead>
                        <tbody>
                        {ClassicalRegisters.map((cState, index) => (                           
                            this.evaluateRow(cState)
                        ))}
                        </tbody>
                    </Table>
                    <Table striped bordered hover>
                        <thead>
                            <tr>
                                <th>State</th>
                                <th>Quantum State</th>
                            </tr>
                        </thead>
                        <tbody>
                        {StateVector.map((qState, index) => (
                            <tr>
                                <td>
                                    {this.handleIndex(index, svLength)}
                                </td>
                                <td>
                                    {qState}
                                </td>                                
                            </tr>
                        ))} 
                        </tbody>
                    </Table>                                  
                </div>
        }
    }
}

export default MainContainer;