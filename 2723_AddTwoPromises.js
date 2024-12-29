
// /**
//  * @param {Promise} promise1
//  * @param {Promise} promise2
//  * @return {Promise}
//  */

var addTwoPromises = async function(promise1, promise2) 
{
    let sum = 0;
    Promise.all([promise1,promise2]).then((result) => {
        console.log(result);
        sum = result.reduce((sum,currVal) => sum + currVal)
        return sum;
    });
};

addTwoPromises(Promise.resolve(2), Promise.resolve(2))
.then(console.log); // 4
 