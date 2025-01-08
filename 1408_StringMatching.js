

/**
 * @param {string[]} words
 * @return {string[]}
 */
var stringMatching = function(words) 
{
    let result = [];
    let str = words.join(",");
    console.log(str);
    for(word of words) {
        if(str.indexOf(word) !== str.lastIndexOf(word)) {
            result.push(word);
        }
    }
    return result;  
};

let main = function() {
    let words = ["uexk","aeuexkf","wgxih","yuexk","gxea","yuexkm","ypmfx","jjuexkmb","wqpri","aeuexkfpo","kqtnz","pkqtnza","nrbb","hmypmfx","krqs","jjuexkmbyt","zvru","ypmfxj"]
    console.log(stringMatching(words));
}
    
main();