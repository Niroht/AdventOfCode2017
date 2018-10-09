namespace AdventOfCodeFSharp.Tests

open System
open Microsoft.VisualStudio.TestTools.UnitTesting
open AdventOfCodeFSharp;

[<TestClass>]
type InverseCaptchaTests () =

    [<TestMethod>]
    member this.InverseCaptcha_PairsOfRepeatedDigits() =
        // arrange
        let result = InverseCaptcha.CalculateInverseCaptcha "1122"
        
        // assert
        Assert.AreEqual(3, result);

    [<TestMethod>]
    member this.InverseCaptcha_AllRepeatingDigits() =
        // arrange
        let result = InverseCaptcha.CalculateInverseCaptcha "1111"

        // assert
        Assert.AreEqual(4, result);

    [<TestMethod>]
    member this.InverseCaptcha_NoRepeatingDigits() =
        // arrange
        let result = InverseCaptcha.CalculateInverseCaptcha "1234"

        // assert
        Assert.AreEqual(0, result);

    [<TestMethod>]
    member this.InverseCaptcha_RepeatingDigitAtEnd() =
        // arrange
        let result = InverseCaptcha.CalculateInverseCaptcha "91212129"

        // assert
        Assert.AreEqual(9, result);

    [<TestMethod>]
    member this.InverseCaptchaPartTwo_PairsOfRepeatingDigits() =
        // arrange
        let result = InverseCaptcha.CalculateInverseCaptchaPartTwo "1212"

        // assert
        Assert.AreEqual(6, result);

    [<TestMethod>]
    member this.InverseCaptchaPartTwo_NoRepeatingDigits() =
        // arrange
        let result = InverseCaptcha.CalculateInverseCaptchaPartTwo "1221"

        // assert
        Assert.AreEqual(0, result);

    [<TestMethod>]
    member this.InverseCaptchaPartTwo_SingleRepeatingSet() =
        // arrange
        let result = InverseCaptcha.CalculateInverseCaptchaPartTwo "123425"

        // assert
        Assert.AreEqual(4, result);

    [<TestMethod>]
    member this.InverseCaptchaPartTwo_TrioOfRepeatingDigits() =
        // arrange
        let result = InverseCaptcha.CalculateInverseCaptchaPartTwo "123123"

        // assert
        Assert.AreEqual(12, result);

    [<TestMethod>]
    member this.InverseCaptchaPartTwo_OneDigitRepeatedFourTimes() =
        // arrange
        let result = InverseCaptcha.CalculateInverseCaptchaPartTwo "12131415"

        // assert
        Assert.AreEqual(4, result);