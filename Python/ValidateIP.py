class ValidateIP:
    @staticmethod
    def validIPAddress(queryIP: str) -> str:
        dot, colon = 0, 0

        for ch in queryIP:
            if ch == '.': 
                dot += 1
            if ch == ':': 
                colon += 1
        if dot != 3 and colon != 7:
            return "Neither"
        if dot > 0:
            values = queryIP.split('.')
            if len(values) != 4:
                return "Neither"
            for value in values:
                if len(value) > 1 and value[0] == '0':
                    return "Neither"
                for ch in value:
                    if not ch.isdigit():
                        return "Neither"
                if len(value) == 0 or len(value) > 3 or int(value) < 0 or int(value) > 255:
                    return "Neither"
            return "IPv4"
        else:
            values = queryIP.split(':')
            if len(values) != 8:
                return "Neither"
            for value in values:
                if len(value) > 4 or len(value) == 0:
                    return "Neither"
                for ch in value:
                    if not (ch.isdigit() or 'a' <= ch <= 'f' or 'A' <= ch <= 'F'):
                        return "Neither"
            return "IPv6"
    
print(ValidateIP.validIPAddress("172.16.254.1"))
print(ValidateIP.validIPAddress("2001:db8:85a3:0:8a2E:0370:7334:0370"))
print(ValidateIP.validIPAddress("2001:db8:85a3:0::8a2E:0370:7334:"))
print(ValidateIP.validIPAddress("1e1.4.5.6"))
