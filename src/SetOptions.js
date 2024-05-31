import links from './links';

async function fetchAll(links){
    const response = await Promise.all(Object.values(links).map(url => fetch(url)));
    const data = await Promise.all(response.map(response => response.text()));
    return data;
}

const options = await fetchAll(links).then((data) => {
    return data;
}); 

let op = {}
function setOptions(){
    const keys = Object.keys(links);
    for(let i=0; i< keys.length; i++){
        op[keys[i]] = options[i];
    }
}
setOptions();
export default op;

