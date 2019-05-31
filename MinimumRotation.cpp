
int fun(string str){
    str = str + str;
    int len = (int)str.length();

    int i = 0, j = 1, k = 0;
    while (j + k < len && i + k < len) {
        if(str[i + k] == str[j + k]) k++;
        else if(str[i+k] < str[j+k]){
            j = max(j + k + 1, i + 1);
            k = 0;
        }
        else if(str[i+k] > str[j+k]){
            i = max(i + k + 1, j + 1);
            k = 0;
        }
    }
    return min(i, j);
}
