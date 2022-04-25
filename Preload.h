//
// Created by mpiot on 15.04.2022.
//

#ifndef NAI_PROJEKT4_PRELOAD_H
#define NAI_PROJEKT4_PRELOAD_H
auto validatePath (const string& str) {
    auto file = ifstream(str);
    auto a = file.is_open();
    return a;
}
auto string_conv(int argc, char *argv[]){
    string str;
    auto stringi=std::vector<string>();
    for (int i = 1; i < argc; i++){
        str=argv[i];
        stringi.push_back(str);
    }
    return stringi;
}
auto validateAll(vector<string> stringi){
    if (stringi.size()==2)
        if (stoi(stringi[01])>0)
                return validatePath(stringi[0]);

    return false;

}
template <typename T>
auto printVector(vector<T> vec){
    for(auto i:vec){
        cout<<i<<" ";
    }
}
#endif //NAI_PROJEKT4_PRELOAD_H
