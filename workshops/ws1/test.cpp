// strStr("abcdefghijklmnopqrstuvwxyz", "jkl")
// Expected output: jklmnopqrstuvwxyz
const char* strStr(const char* str1, const char* str2) {
    int i = 0;
    int j = 0;
    while (str2[j] != '\0') {
        // Find first matching character
        if (str2[j] != str1[i]) {
            i++;
        }
        // Find subsequent matches??
        while (str2[j] == str1[i]) {
            ++i;
            ++j;
            if (str2[j] == '\0') {
                return &str1[i];
            }
        }
    }
    return nullptr;
}