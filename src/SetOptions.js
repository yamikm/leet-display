import links from './links';

// async function fetchAll(links){
//     const response = await Promise.all(Object.values(links).map(url => fetch(url)));
//     const data = await Promise.all(response.map(response => response.text()));
//     return data;
// }

// const options = await fetchAll(links).then((data) => {
//     return data;
// }); 

let op = {}
/**
 * This function takes the keys of the links object and uses them to
 * populate the op object with the corresponding values from the links
 * object.
 *
 * The links object is expected to be an object with string keys and
 * string values representing URLs.
 *
 * The op object is expected to be an empty object that will be
 * populated with the values from the links object.
 *
 * The function iterates over the keys of the links object and for each
 * key, it sets the corresponding value in the op object to the value
 * of the links object with that key.
 */
function setOptions(){
    const keys = Object.keys(links);
    for(let i=0; i< keys.length; i++){
        /**
         * Set the value of the op object with the current key to the value
         * of the links object with the same key.
         */
        op[keys[i]] = links[keys[i]];
    }
}
setOptions();
export default op;

