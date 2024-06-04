import React, {useEffect, useState} from 'react';
import CodeEditor from './CodeEditor';

import options from './SetOptions'


function App() {
  const URL = "https://raw.githubusercontent.com/yamikm/leet-display/main/src/algorithms/";
  const [selected, setSelected] = useState("");
  const [data, setData] = useState("");
  const selectOption = (option) =>{
    setSelected(option);
    
  };

  useEffect( () => {
    async function fetchData(){
      var response = await fetch(URL + options[selected]);
      var text = await response.text();
      setData(text);
    }
    fetchData();
    
  },[selected] );
  console.log("OPTIONS:" , options)
 
  return (
    <div style={{display: 'flex', justifyContent:'space-between'}}>
      
        <div style={{overflow:'auto', height:'100vh'}}>
          {Object.keys(options).map((option, index)=> (
            <div
              key={index}
              style={{
                backgroundColor: selected === option ? 'lightgray': 'white',
                cursor: 'pointer',
                padding: '10px',
                borderBottom: '1px solid black'
              }}
              onClick={() => selectOption(option)}
            >
              {option}
            </div>  
          ))}

        </div>
      
      <div style={{width:'70%', height: '100vh' }}>

      {
        selected && (
          <div>
            <CodeEditor initialCode={data} rows="10" cols="50" />
          </div>
      )}
      </div>
      
    </div>
  );
}

export default App;
