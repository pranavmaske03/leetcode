
/**
 * @param {string[]} words
 * @param {number[][]} queries
 * @return {number[]}
 */
var vowelStrings = function(words, queries) 
{
    let vowels = "aeiou";
    prefixSumVowel = new Array(words.length).fill(0);
    
    if(vowels.includes(words[0].at(0)) && vowels.includes(words[0].at(-1))) {
        prefixSumVowel[0] = 1;
    }

    for(let i = 1; i < words.length; i++) {

        if(vowels.includes(words[i].at(0)) && vowels.includes(words[i].at(-1))) {
            prefixSumVowel[i] += prefixSumVowel[i-1] + 1;
        } else {
            prefixSumVowel[i] = prefixSumVowel[i-1];
        }
    }

    result = [];
    for(let i = 0; i < queries.length; i++) {

        const [left,right] = queries[i];
        const countWord = prefixSumVowel[right] - (left == 0 ? 0 : prefixSumVowel[left-1]);
        result.push(countWord);
    }
    return result;   
};

let main = function() {

    let words =  ["b","rmivyakd","kddwnexxssssnvrske","vceguisunlxtldqenxiyfupvnsxdubcnaucpoi","nzwdiataxfkbikbtsjvcbjxtr","wlelgybcaakrxiutsmwnkuyanvcjczenuyaiy","eueryyiayq","bghegfwmwdoayakuzavnaucpur","ukorsxjfkdojcxgjxgmxbghno","pmgbiuzcwbsakwkyspeikpzhnyiqtqtfyephqhl","gsjdpelkbsruooeffnvjwtsidzw","ugeqzndjtogxjkmhkkczdpqzwcu","ppngtecadjsirj","rvfeoxunxaqezkrlr","adkxoxycpinlmcvmq","gfjhpxlzmokcmvhjcrbrpfakspscmju","rgmzhaj","ychktzwdhfuruhpvdjwfsqjhztshcxdey","yifrzmmyzvfk","mircixfzzobcficujgbj","d","pxcmwnqknyfkmafzbyajjildngccadudfziknos","dxmlikjoivggmyasaktllgmfhqpyznc","yqdbiiqexkemebyuitve"];
    let queries = [[5, 21],[17, 22],[19, 23],[13, 15],[20, 23],[21, 23],[6, 20],[1, 8],[15, 20],[17, 22],[6, 6],[1, 2],[4, 11],[14, 23],[7, 10],[16, 22],[20, 22],[21, 22],[15, 18],[5, 16],[17, 23]];

    console.log(vowelStrings(words,queries));
}

main();