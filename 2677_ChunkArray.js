

/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */

var chunk = function(arr, size) 
{
   const res = [];

  // Maintain a variable for the current chunk we're assembling.
  let currentChunk = [];

  for (const element of arr) {
    currentChunk.push(element);

    // When we have a full chunk, add it to the result and reset.
    if (currentChunk.length === size) {
      res.push(currentChunk);
      currentChunk = [];
    }
  }
    
  // Unfortunately this means we need an additional check for the last chunk.
  if (currentChunk.length > 0) {
    res.push(currentChunk);
  }

  return res;
};

let main = function() {
    chunk();
}

main();
