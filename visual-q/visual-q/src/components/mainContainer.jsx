import React from "react"
import "./mainContainer.css"
import Form from 'react-bootstrap/Form'
import Button from 'react-bootstrap/Button'

const electron = window.require('electron');
const ipcRenderer = electron.ipcRenderer;



async function sendFile(val){
    const res = await ipcRenderer.sendSync('sendFile', val);
    console.log(res);
    return res;
}

class MainContainer extends React.Component{

    constructor(props){
        super(props);
        this.state = {value: '', result: ''};
        this.handleSubmit = this.handleSubmit.bind(this);
        this.handleChange = this.handleChange.bind(this);
        this.renderOutput = this.renderOutput.bind(this);
    }
    
    async handleSubmit(event){
        const fileName = "output.qasm";
        console.log(this.state.value);
        const val = [fileName, this.state.value];
        try{
            var res = await sendFile(val);
            this.setState({value: this.state.value, result: res});
        }
        catch(e){
            console.log("Error during valkyrie run")
        }
        return false;
    }

    handleChange(event){
        this.setState({value: event.target.value, result: this.state.result});
    }
    
    render(){
        return (<div className="mainContent">
            <div className="write-code">
                Hello there, please enter your QASM code below:
            </div>
            <div>
                <Form>
                    <Form.Group controlId="qasmInput">
                        <Form.Label>QASM Input</Form.Label>
                        <Form.Control 
                            as="textarea"
                            rows={10}
                            placeholder="OPENQASM 2.0;"
                            defaultValue="OPENQASM 2.0;"
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

    renderOutput(){
        if(this.state.result === ''){
            return <div>Please click submit to see output</div>
        } else {
            return <div>
                Output:
                <br/>
                    <pre>
                    {this.state.result}
                    </pre>                
                </div>
        }
    }
}

export default MainContainer;