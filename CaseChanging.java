class caseChanging {
    static char change(char ch){
        if Character.isUpperCase(ch){
        return Character.toLowerCase(ch)   
            }
        else {
        return Character.toUpperCase(ch)
            }
     }
    static String changeCase(String string) {
        String s = "";
        for (int i = 0, n = string.length(); i < n; i++) {
            char c = string.charAt(i);
            c=change(c)
            s = s + c;
        }
        return s;
    }

    public static void main(String[] args) {
        System.out.println(changeCase("Harishma 89;jdhhewkjrhkdbcSBD"));
    }
}
