namespace AdventOfCodeFSharp

module InverseCaptcha = 
    let inline charToInt c = int c - int '0'
    let inline add x y = x + y

    let CalculateInverseCaptcha (input:string) =
        let solution = ref 0
        for i in 0 .. input.Length - 1 do
            let currentValueAsInt = input.[i] |> charToInt
            let nextIndex = if i = input.Length - 1 then 0 else i + 1
            let nextValueAsInt = input.[nextIndex] |> charToInt
            if currentValueAsInt = nextValueAsInt then solution := !solution + currentValueAsInt
        solution.Value

    let CalculateInverseCaptchaPartTwo (input:string) =
        let solution = ref 0
        for i in 0 .. input.Length - 1 do
            let currentValueAsInt = input.[i] |> charToInt
            let desiredIndex = i + input.Length / 2;
            let nextIndex = if desiredIndex > input.Length - 1 then  desiredIndex - input.Length else desiredIndex
            let nextValueAsInt = input.[nextIndex] |> charToInt
            if currentValueAsInt = nextValueAsInt then solution := !solution + currentValueAsInt
        solution.Value