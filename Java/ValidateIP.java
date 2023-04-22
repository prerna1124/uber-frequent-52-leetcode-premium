package Java;

class ValidateIP {
    public static String validIPAddress(String queryIP) {
        int dot = 0, colon = 0;

        for(char ch : queryIP.toCharArray()) {
            if(ch == '.') dot += 1;
            if(ch == ':') colon += 1;
        }
        if(dot != 3 && colon != 7) return "Neither";
        if(dot > 0) {
            String[] values = queryIP.split("\\.");
            if(values.length != 4) return "Neither";
            for(int i = 0; i < values.length; i++) {
                if(values[i].length() > 1 && values[i].charAt(0) == '0') {
                    return "Neither";
                }
                for(char ch : values[i].toCharArray()) {

                    if(!Character.isDigit(ch)) {
                        return "Neither";
                    }
                }

                if(values[i].length() == 0 || values[i].length() > 3 || Integer.parseInt(values[i]) < 0 || Integer.parseInt(values[i]) > 255) {
                    return "Neither";
                }
                
            } 
            return "IPv4";
        }
        else {
            String[] values = queryIP.split(":");

            if(values.length != 8) return "Neither";

            for(int i = 0; i < values.length; i++) {
                if(values[i].length() > 4 || values[i].length() == 0) {
                    return "Neither";
                }
                for(char ch : values[i].toCharArray()) {
                    if(!Character.isDigit(ch) && (ch < 'a' || ch > 'f') && (ch < 'A' || ch > 'F')) {
                        return "Neither";
                    }
                }
            } 
            return "IPv6";
        }
    }
    
    public static void main(String[] args) {
        System.out.println(validIPAddress("172.16.254.1"));
        System.out.println(validIPAddress("2001:db8:85a3:0:8a2E:0370:7334:0370"));
        System.out.println(validIPAddress("2001:db8:85a3:0::8a2E:0370:7334:"));
        System.out.println(validIPAddress("1e1.4.5.6"));
    }

}
