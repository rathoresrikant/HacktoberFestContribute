class caseChanging {
    static String changeCase(String string) {
        String s = "";
        for (int i = 0, n = string.length(); i < n; i++) {
            char c = string.charAt(i);
            if (c >= 'A' && c <= 'Z') {
                c = Character.toLowerCase(c);
            } else {
                c = Character.toUpperCase(c);
            }
            s = s + c;
        }
        return s;
    }

    public static void main(String[] args) {
        System.out.println(changeCase("Harishma 89;jdhhewkjrhkdbcSBD"));
    }
}
