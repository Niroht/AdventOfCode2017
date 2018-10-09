import { BasicPassphraseValidate, ComplexPassphraseValidate } from '../dayFour.js';
import assert from 'assert';

export function RunTests(){
    describe('Day Four', function() {
        describe('BasicPassphraseValidate()', function() {
            it('Should return valid for basic valid', function() {
                assert.equal(BasicPassphraseValidate('aa bb cc dd ee'), true);
            });
            it('Should return invalid for basic invalid', function() {
                assert.equal(BasicPassphraseValidate('aa bb cc dd aa'), false);
            });
            it('Should return valid for an input that is almost invalid', function() {
                assert.equal(BasicPassphraseValidate('aa bb cc dd aaa'), true);
            });
        });
        describe('ComplexPassphraseValidate()', function() {
            it('Should return valid for basic valid', function() {
                assert.equal(ComplexPassphraseValidate('abcde fghij'), true);
            });
            it('Should return invalid for a single anagram', function() {
                assert.equal(ComplexPassphraseValidate('abcde xyz ecdab'), false);
            });
            it('Should return valid when lengths are different', function() {
                assert.equal(ComplexPassphraseValidate('a ab abc abd abf abj'), true);
            });
            it('Should return valid when only two characters are used', function() {
                assert.equal(ComplexPassphraseValidate('iiii oiii ooii oooi oooo'), true);
            });
            it('Should return invalid when everything is an anagram', function() {
                assert.equal(ComplexPassphraseValidate('oiii ioii iioi iiio'), false);
            });
        })
    });
}