export function CalculateChecksum(input){
    let sum = 0;

    input.forEach(row => {
        let largestNumber = 0;
        let smallestNumber = 0

        row.forEach(column => {
            if (column > largestNumber){
                largestNumber = column;
            }
            if (smallestNumber === 0 || column < smallestNumber){
                smallestNumber = column;
            }
        });

        sum += largestNumber - smallestNumber;
    });

    return sum;
}

export function SumEvenlyDivisibleValues(input){
    let sum = 0;
    
        input.forEach(row => {
            let foundEvenlyDivisibleValue = false;

            for (let column = 0; column < row.length; column++){
                for (let i = 0; i < row.length; i++){
                    if (i !== column && row[column] % row[i] === 0){
                        sum += row[column] / row[i];
                        foundEvenlyDivisibleValue = true;
                    }
                    if(foundEvenlyDivisibleValue) break;
                }
                if(foundEvenlyDivisibleValue) break;
            }
        });
    
        return sum;
}