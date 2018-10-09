import unittest
from AdventOfCodePy import InverseCaptcha

class InverseCaptchaTest(unittest.TestCase):


    def test_inverse_captcha_pairs_of_repeating_digits(self):
        result = InverseCaptcha.InverseCaptcha.calculate_inverse_captcha("1122")
        self.assertEqual(3, result);
        
    def test_inverse_captcha_all_repeating_digits(self):
        result = InverseCaptcha.InverseCaptcha.calculate_inverse_captcha("1111")
        self.assertEqual(4, result);

    def test_inverse_captcha_no_repeating_digits(self):
        result = InverseCaptcha.InverseCaptcha.calculate_inverse_captcha("1234")
        self.assertEqual(0, result);
        
    def test_inverse_captcha_repeating_digit_at_end(self):
        result = InverseCaptcha.InverseCaptcha.calculate_inverse_captcha("91212129")
        self.assertEqual(9, result);
    
    def test_inverse_captcha_part_two_no_repeating_digits(self):
        result = InverseCaptcha.InverseCaptcha.calculate_inverse_captcha_part_two("1221")
        self.assertEqual(0, result);
    
    def test_inverse_captcha_part_two_single_repeating_set(self):
        result = InverseCaptcha.InverseCaptcha.calculate_inverse_captcha_part_two("123425")
        self.assertEqual(4, result);
    
    def test_inverse_captcha_part_two_trio_of_repeating_digits(self):
        result = InverseCaptcha.InverseCaptcha.calculate_inverse_captcha_part_two("123123")
        self.assertEqual(12, result);
        
    def test_inverse_captcha_part_two_one_digit_repeated_four_times(self):
        result = InverseCaptcha.InverseCaptcha.calculate_inverse_captcha_part_two("12131415")
        self.assertEqual(4, result);

if __name__ == "__main__":
    unittest.main()