class InverseCaptcha(object):
    @staticmethod
    def calculate_inverse_captcha(captcha_to_calculate):
        result = 0;
        for index, item in enumerate(captcha_to_calculate):
            next_index = 0 if index == len(captcha_to_calculate) - 1 else index + 1
            if (item == captcha_to_calculate[next_index]):
                result += int(item)
            
        return result
    
    @staticmethod
    def calculate_inverse_captcha_part_two(captcha_to_calculate):
        result = 0;
        for index, item in enumerate(captcha_to_calculate):
            desired_index = index + len(captcha_to_calculate) // 2
            next_index = desired_index if desired_index < len(captcha_to_calculate) else desired_index - len(captcha_to_calculate) 
            if (item == captcha_to_calculate[next_index]):
                result += int(item)
            
        return result