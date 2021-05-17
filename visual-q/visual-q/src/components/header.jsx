import React from "react"
import "./header.css"

class Header extends React.Component{
    render(){
        return (
        <div class="header">
            <div class="title-x">
                Visual Q
            </div>
            <div class="poppin">
                Powered by Valkyrie
            </div>           
            
        </div>)       
    }
}

export default Header;