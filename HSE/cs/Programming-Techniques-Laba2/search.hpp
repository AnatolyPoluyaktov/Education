//
// Created by drope on 26.02.2020.
//

#ifndef LABA2_SEARCH_HPP
#define LABA2_SEARCH_HPP

#include <vector>
#include <map>
#include <algorithm>
namespace srh{
    template<typename obj,typename keytype>
    std::vector<obj>linear(std::vector<obj>& vec,keytype key){
        std::vector<obj>ans;
        for(size_t i =0; i<vec.size();++i){
            if(vec[i].GetPort()==key)
                ans.push_back(vec[i]);
        }

        return ans;
    }
    template<typename obj,typename keytype>
    int upper_bound(std::vector<obj>& vec,keytype key){
        int l=0,r=vec.size(),m;
        if(vec[0].GetPort()>key)
            return 0;
        while((l+1)<r){
            m=(l+r)/2;
            if(vec[m].GetPort()>key)
                r=m;
            else
                l=m;
        }
        return r;
    }
    template<typename obj,typename keytype>
    int lower_bound(std::vector<obj>& vec, keytype key){
        int l=0,r=vec.size(),m;
        if(vec[0].GetPort() >=key)
            return 0;
        while(l+1<r){
            m=(l+r)/2;
            if(vec[m].GetPort()>= key)
                r=m;
            else
                l=m;
        }
        return r;
    }
    template<typename obj,typename keytype>
    std::pair<int,int> binary(std::vector<obj>& vec,keytype key){
        int l=lower_bound(vec,key);
        //std::pair<int,int>p;
        int r=upper_bound(vec,key);
        std::pair<int,int>p{l,r};
        return p;
    }

    template <typename obj>
    std::multimap<std::string,obj> formed_multimap(std::vector<obj>& vec){
        std::multimap<std::string, obj> mp;
        std::vector<obj>ans;
        for(size_t i =0;i<vec.size();++i){
            mp.insert(std::make_pair(vec[i].GetPort(),vec[i]));

        }
        return mp;
    }


}
#endif //LABA2_SEARCH_HPP
