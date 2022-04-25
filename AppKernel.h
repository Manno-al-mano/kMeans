//
// Created by mpiot on 15.04.2022.
//

#ifndef NAI_PROJEKT4_APPKERNEL_H
#define NAI_PROJEKT4_APPKERNEL_H
auto prepare(vector<double> & wektorDoubli, string& str){
    for (auto i=0;i<str.size();i++){
        if (str[i]==','){
            wektorDoubli.push_back(atof(str.substr(0,i).c_str()));
            str.erase(0,i+1);
            i=0;

        }
    }

}

auto splitFileTest(const string &path, vector<vector<double>> & vectorTestowy) {
    auto trainingfile = ifstream(path);
    auto wektorDoubli = vector<double>();
    for (auto str = string(); getline(trainingfile, str);) {
        prepare(wektorDoubli, str);
        vectorTestowy.push_back(wektorDoubli);
        wektorDoubli.clear();

    }
}


    auto AppKernel(int argc, char *argv[]) {
        auto stringi = vector<string>();
        stringi = string_conv(argc, argv);
        if (!validateAll(stringi)) {
            cout << "Podano niewłaściwe Flagi" << "\n";
            return 0;
        }

        auto vectorWarosci = vector<vector<double >>();
        splitFileTest(stringi[0],vectorWarosci);
        auto vectorCentrow = vector<vector<double >>();
        for(auto i=0;i<stoi(stringi[1]);i++){
            vectorCentrow.push_back(vectorWarosci[i]); }
            kMeans(vectorWarosci,vectorCentrow);


    }
#endif //NAI_PROJEKT4_APPKERNEL_H
