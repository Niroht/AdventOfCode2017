export function InverseCaptcha(input){
    let sum = 0;
    for (let i = 0; i < input.length; i++) {
        let nextIndex = i === input.length-1 ? 0 : i + 1;
        if (input[i] === input[nextIndex]){
            sum =  sum + +input[i];
        }
    }

    return sum;
}

export function InverseCaptchaPartTwo(input){
    let sum = 0;
    for (let i = 0; i < input.length; i++) {
        let desiredIndex = i + input.length / 2;
        let nextIndex = desiredIndex > input.length - 1 ? desiredIndex - input.length : desiredIndex;
        if (input[i] === input[nextIndex]){
            sum =  sum + +input[i];
        }
    }

    return sum;
}