import React from "react"

const electron = window.require('electron');
const ipcRenderer = electron.ipcRenderer;

async function sendFile(val){
    const res = await ipcRenderer.sendSync('sendFile', val)
    
    // res.then(() => {
    //     console.log("File saved");
    // }).catch((error) => {
    //     console.log(error);
    // })
    return res;
}

class MainContainer extends React.Component{   
    
    render(){
        return (<div>
            Hello
        </div>)
    }
}

export default MainContainer;