//
// Created by NOAH on 2020/4/19.
//

#ifndef FILE_MAP_SET_FILTER_H
#define FILE_MAP_SET_FILTER_H

#include <map>
#include <set>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class file_map_set_filter {
};

// 初始化排除词汇set
void init_exclusion_set(set<string> &exs) {
    //定义排除数组
    static string excluded_words[15] = {
            "a", "an", "the", "and", "or",
            "is", "are", "can", "had", "with",
            "of", "for", "him", "her", "it"
    };
    // 将排除数组加入set
    exs.insert(excluded_words, excluded_words + 15);
}

// 读取文件
void process_file(map<string, int> &word_count,
                  const set<string> &exclue_set,
                  ifstream &ifile) {
    string word;
    while (ifile >> word) {
        // 读取文件中的word 若在排除set中 则跳过计数 继续执行下个判断
        if (exclue_set.count(word)) continue;
        //当执行到这一句时，则证明当前word不在set中，将word写入map中 若word已存在 则value++
        word_count[word]++;
    }
}

//用户查询交互
void user_query(map<string, int> &word_map) {
    // 输入待查询word
    string search_word;
    cout << "Enter:(q to quit)";
    cin >> search_word;
    //查询用户输入word 若为q则退出
    while (search_word.size() && search_word != "q") {
        map<string, int>::const_iterator it;
        if ((it = word_map.find(search_word)) != word_map.end())
            cout << "Found: " << it->first
                 << " occours: " << it->second
                 << " times." << endl;
        else cout << search_word << " was not found" << endl;

        cout << "\nAnother search?(q to quit) ";
        cin >> search_word;
    }
}

//显示各单词出现次数，将map输出
void display(const map<string, int> &word_map,
             ofstream &os) {
    map<string, int>::const_iterator
            iter = word_map.begin(),
            end_it = word_map.end();
    while (iter != end_it) {
        os << iter->first << " ( "
           << iter->second << " ) " << endl;
        ++iter;
    }
    os << endl;
}

#endif //FILE_MAP_SET_FILTER_H
