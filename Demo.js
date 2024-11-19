function sumOfevenFibonacci(limit) {
    // Define variable sum
    let sum = 0;
    let val1 = 0;
    let val2 = 1;
    let value = 0;
    while(limit--)
    {
        value = val1 + val2;
        if(value % 2 === 0) sum += value;
        val1 = val2;
        val2 = value;
    }

    return sum;
}


console.log(sumOfevenFibonacci(8));