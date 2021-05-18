import logo from './logo.svg';
import './App.css';
import Header from './components/header'
import MainContainer from './components/mainContainer'
import "./components/mainContainer.css"

import 'bootstrap/dist/css/bootstrap.min.css';

function App() {
  return (
    <div className="wrapper">
      <Header/>
      <MainContainer/>
    </div>   
  );
}

export default App;
