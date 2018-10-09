import { InverseCaptcha, InverseCaptchaPartTwo } from './dayOne.js';
import { CalculateChecksum, SumEvenlyDivisibleValues } from './dayTwo.js';
import { BasicPassphraseValidate, ComplexPassphraseValidate } from './dayFour.js';
import { dayOne, dayTwo, dayFour } from './inputs.js';

function runDayOne() {
	console.log("Day One");
	console.log(`${InverseCaptcha(dayOne)}`);
	console.log(`${InverseCaptchaPartTwo(dayOne)}`);
}

function runDayTwo() {
	let parsedInput = dayTwo.split('\n').map(line => line.match(/\S+/g).map(item => +item));

	console.log('Day Two');
	console.log(`${CalculateChecksum(parsedInput)}`);
	console.log(`${SumEvenlyDivisibleValues(parsedInput)}`);
}

function runDayFour() {
	let dayFourRows = dayFour.split('\n');
	console.log('Day Four')
	console.log(`${dayFourRows.filter(x => BasicPassphraseValidate(x)).length}`);
	console.log(`${dayFourRows.filter(x => ComplexPassphraseValidate(x)).length}`);	
}

runDayOne();
runDayTwo();
runDayFour();