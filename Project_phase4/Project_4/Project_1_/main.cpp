//
//  main.cpp
//  Project_1_
//
//  Created by Elahe on 12/20/15.
//  Copyright (c) 2015 Elahe & Amineh. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include "Phase1_func.h"

#define size_hash 1000

int main()
{
    std:: cout<< "Please wait while the data is being processed...\n";
    std:: string address;
    address = "/Users/codeWorm/Desktop/data 2";
    std:: vector <Files> all_files;
    Find_adrs(address, all_files);
    
    std::vector<Words> hash[size_hash];
    Insert_Hash(all_files, hash, size_hash);
    
    std::vector<std::string> hash_dict[size_hash];
    Insert_Hash_Dict(hash_dict, size_hash);
    std::vector<char> keyboard[26];
    Insert_keyboard(keyboard);
    std:: vector<std::pair<std::string, std::string> > mistakes;
    
    while (true)
        {
        int stage;
        std:: cout<< "Choose one of the following options:\n";
        std:: cout<< "1) Count the repetitions of a word\n";
        std:: cout<< "2) Replace a word\n";
        std:: cout<< "3) Find the paragraph of a word\n";
        std:: cout<< "4) Show stemmed file\n";
        std:: cout<< "5) Search via Hash\n";
        std:: cout<< "6) Boolean search\n";
        std:: cout<< "7) Smart Search\n";
        std:: cout<< "8) Exit\n";
        std:: cin>> stage;
        
        
        
        //std:: vector <std::thread> th;
        
        switch (stage)
        {
            case 1:
            {
                std:: string target;
                std:: cout<<"Enter your word\n";
                std:: cin>> target;
                for (int i = 0; i < all_files.size(); i++)
                {
                    all_files[i].Cnt_Wrd(target);
                }
                break;
            }
                
            case 2:
            {
                std:: string target;
                std:: cout<<"Enter the first word\n";
                std:: cin>> target;
                std::string alter;
                std::cout<<"Enter the second word\n";
                std::cin>> alter;
                for (int i = 0; i < all_files.size(); i++)
                {
                    all_files[i].Rpl_Wrd(target, alter);
                }
                break;
            }
                
            case 3:
            {
                std:: string target;
                std:: cout<<"Enter your word\n";
                std:: cin>> target;
    //         **** the following code run the third case in the ordinary way ***
                
                for (int i = 0; i < all_files.size(); i++)
                {
                    all_files[i].Prg_Wrd(target);
                }
                
    ////            ***** thread way *****
    //            for (int i = 0; i < all_files.size(); i++)
    //            {
    //          //      std:: thread t1(Prg_Wrd_Th,all_files[i].content, target, all_files[i].name);
    //                
    //               th.push_back(std:: thread (Prg_Wrd_Th,all_files[i].content, target, all_files[i].name));
    //            }
    //            std::vector<std::thread>::iterator originalThread = th.begin();
    //            while(originalThread != th.end())
    //            {
    //                originalThread -> join();
    //                originalThread ++;
    //            }
                 break;
            }
            
            case 4:
            {
                for (int i = 0; i < all_files.size(); i++)
                {
                    std::cout<<std::endl<<std::endl<<all_files[i].stmstr;
                }
                
                break;
            }
                
            case 5:
            {
                std:: string target;
                std:: cout<<"Enter your word\n";
                std:: cin>> target;
                Search_Hash(target, hash, size_hash);
                break;
            }
             
            case 6:
            {
                getchar();
                std::cout << "Enter your phrase:\n";
                std:: string input;
                std::getline(std::cin, input);
                Rpl_Bool(input, "AND", "&");
                Rpl_Bool(input, "OR", "|");
                Rpl_Bool(input, "NOT", "!");
                Del_Spaces(input);
                Boolean_Search(input, size_hash, hash, all_files.size(), all_files);
                break;
            }
                
            case 7:
            {
                std::cout << "Enter your word:\n";
                std:: string input;
                std::cin >> input;
                Smart_Search(input, hash_dict, mistakes, size_hash, keyboard);
                
                break;
            }
                
            case 8:
            {
                goto out;
            }
                
            default:
            {
                std:: cout << "We're Shakh and we know it!\n";
                break;
            }
        }
        std::cout << "Do you wish to continue searching?\n";
        std::cout << "1) Yes.\n2) No.\n";
        int flag;
        std::cin >> flag;
        if (flag == 2)
        {
            std::cout << "Thank you for choosing our search engine! We sure wish to see you soon!\n";
            goto out;
        }
        std::cout << std::endl << std::endl;
    }
out:;
    return 0;
}
