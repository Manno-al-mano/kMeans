//
// Created by mpiot on 15.04.2022.
//

#ifndef NAI_PROJEKT4_KMEANS_H
#define NAI_PROJEKT4_KMEANS_H
auto countDist(const vector<double>&a,const vector<double >&b){
    double distance =0;
    for(auto i = 0;i<a.size();i++){
        distance += pow((a[i]-b[i]),2);
    }
    return distance;

}
auto group(const vector<vector<double>>&wartosci,const vector<vector<double>>&centra){
    auto vec = vector<pair<vector<double>,int>>();
    double distance;
    double distance2;
    int centrum=0;
    auto per = pair<vector<double>,int>();
    for(auto j =0;j<wartosci.size();j++){
        distance=countDist(wartosci[j],centra[centrum]);

        for(auto i =0;i<centra.size();i++){
            distance2=countDist(wartosci[j],centra[i]);
            if (distance>distance2)
            {
                distance=countDist(wartosci[j],centra[i]);
                centrum=i;
            }
        }
        per.first=wartosci[j];
        per.second=centrum;
        vec.push_back(per);
    }
    return vec;
}

auto alterCenters(vector<vector<double>>&centra,const vector<pair<vector<double>,int>> &vec) {
    auto avg = vector<double>();
    for (auto val:centra[0]) {
        avg.push_back(0);
    }
    int count = 0;
    for (int i = 0; i < centra.size(); i++) {
        for (auto per:vec) {
            if (per.second == i) {
                count++;
                for (auto j = 0; j < per.first.size(); j++) {
                    avg[j] += per.first[j];

                }
            }
        }
        cout << "center " << i << "\n";
        for (auto j = 0; j < avg.size(); j++) {
            cout << avg[j] / count << " ";
            if (avg[j] != 0) {

                centra[i][j] = avg[j] / count;
                avg[j] = 0;
            }
        }
        cout << "\n";
        auto sum = 0;
        for (auto per:vec) {
        if (i == per.second)
            sum += countDist(centra[i], per.first);
    }
cout<<"Suma Kwadratow: "<<sum<<"\n";



     count =0;

  }
}




auto epoque(const vector<vector<double>>&wartosci, vector<vector<double>>&centra){
    cout<<"Nowa Epoka"<<"\n";
    auto vec=group(wartosci,centra);
    sort(vec.begin(),vec.end(),
        [](pair<vector<double>,int> a, pair<vector<double>,int>b){return a.second<b.second;});
    alterCenters(centra,vec);
    for(auto per:vec){
        printVector(per.first);
        cout<<"Grupa "<<per.second<<"\n";
    }
}


auto kMeans(const vector<vector<double>>&wartosci, vector<vector<double>>&centra){
    auto finished=false;
    bool same;
    auto vec=vector<vector<double>>();
    while (!finished){
        same= true;
        vec=centra;
        epoque(wartosci,centra);
        for(auto i=0;i<centra.size();i++){
            for(auto j=0; j<centra[i].size();j++){
                if(centra[i][j]!=vec[i][j]){same= false;
                }
            }
        }
        if(same){
            finished= true;
        }
    }
}
#endif //NAI_PROJEKT4_KMEANS_H