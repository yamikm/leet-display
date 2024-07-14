import { useEffect, useState } from 'react';
import AceEditor from 'react-ace';
import 'ace-builds/webpack-resolver';
import 'ace-builds/src-noconflict/mode-c_cpp';
import 'ace-builds/src-noconflict/theme-ambiance';
import 'ace-builds/src-noconflict/theme-github';



const CodeEditor =({initialCode}) =>{
    const [output, setOutput] = useState('');
    const [code, setCode] = useState(initialCode);

    const handleCodeChange = (currCode) =>{
        setCode( currCode);
    }

    useEffect(() => {
        setCode(initialCode);
    },[initialCode]);
    

    const runCode = () => {
        try{
            const originalConsoleLog = console.log;
            let logOutput = '';
            console.log = (...args) => {
                logOutput += args.join(' ') + '\n';
            };
            //Execute the code.
            eval(code);
            //Restore original console.log and set output.
            console.log = originalConsoleLog;
            setOutput(logOutput);
        }catch(error){
            setOutput(`Error: ${error.message}`);
        }
    }

    return (

        <div>
            <AceEditor
                mode="c_cpp"
                theme='github'
                value={code}
                onChange={handleCodeChange}
                name='UNIQUE_ID_OF_DIV'
                editorProps={{$blockScrolling: true}}
                setOptions={{
                    enableBasicAutocompletion: true,
                    enableLiveAutocompletion: true,
                    enableSnippets: true,
                }
                }
                fontSize={14}
                showPrintMargin={true}
                showGutter={true}
                highlightActiveLine={true}
                width='100%'
                height='400px'

                />
                <button onClick={runCode} > RunCode </button>
                <br></br>
                <strong>Output:</strong>
                <pre> {output} </pre>
            
        </div>
    );
}
export default CodeEditor;
