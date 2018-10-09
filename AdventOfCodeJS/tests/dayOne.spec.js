import { InverseCaptcha, InverseCaptchaPartTwo} from '../dayOne.js';
import assert from 'assert';

function RunTests(){
    describe('Day One', function() {
        describe('#InverseCaptcha()', function() {
          it('should sum when encountering pairs of repeating digits', function() {
            assert.equal(InverseCaptcha('1122'), 3);
          });
          it('should sum when encountering only repeating digits', function() {
              assert.equal(InverseCaptcha('1111'), 4);
          });
          it('should not sum when encountering no repeating digits', function() {
              assert.equal(InverseCaptcha('1234'), 0);
          });
          it('should sum when encountering repeating digit at end', function() {
              assert.equal(InverseCaptcha('91212129'), 9);
          });
        });
      
        describe('#InverseCaptchaPartTwo()', function() {
          it('should sum when encountering pairs of repeating digits', function() {
            assert.equal(InverseCaptchaPartTwo('1212'), 6);
          });
          it('should sum when encountering no  repeating digits', function() {
              assert.equal(InverseCaptchaPartTwo('1221'), 0);
          });
          it('should not sum when encountering a single repeating set', function() {
              assert.equal(InverseCaptchaPartTwo('123425'), 4);
          });
          it('should sum when encountering a trio of repeating digits', function() {
              assert.equal(InverseCaptchaPartTwo('123123'), 12);
          });
          it('should sum when encountering one digit repeated four times', function() {
              assert.equal(InverseCaptchaPartTwo('12131415'), 4);
          });
        });
      });      
}

exports.RunTests = RunTests;