import { CalculateChecksum, SumEvenlyDivisibleValues} from '../dayTwo.js';
import assert from 'assert';

export function RunTests(){
    describe('Day Two', function() {
        describe('#CalculateChecksum()', function() {
            it('should calculate a valid checksum', function() {
                let input = [
                    [ 5, 1, 9, 5 ],
                    [ 7, 5, 3 ],
                    [ 2, 4, 6, 8 ]
                ];

                assert.equal(CalculateChecksum(input), 18);
            })
        });
        describe('#SumEvenlyDivisibleValues()', function() {
            it('should sum evenly divisible values', function() {
                let input = [
                    [ 5, 9, 2, 8 ],
                    [ 9, 4, 7, 3 ],
                    [ 3, 8, 6, 5]
                ]

                assert.equal(SumEvenlyDivisibleValues(input), 9);
            })
        })
    });
}

exports.RunTests = RunTests;