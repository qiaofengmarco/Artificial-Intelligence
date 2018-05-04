/*
******************************************************************
* Southeast University Artificial Intelligence Course Project
*
* Author: Qiaofeng Marco LIU
*
* Contact Info: qiaofengmarco@outlook.com
******************************************************************
*/


#include "pack.h"
#include "time.h"
#include "image_processing.hpp"
#include "pgmimage.hpp"
#include "network.hpp"

int main(int argc, char* argv[])
{

    IMAGELIST *train;
    train = imgl_alloc();
    //test1 = imgl_alloc();
    //test2 = imgl_alloc();
   
    imgl_load_images_from_textfile(train, "../all_train1.list");
    //imgl_load_images_from_textfile(test1, "../all_test11.list");
    //imgl_load_images_from_textfile(test2, "../all_test21.list");

    vector<int> net_st;
    int image_size = ROWS(train->list[0]) * COLS(train->list[0]);
    net_st.push_back(image_size);
    net_st.push_back(4);
    net_st.push_back(1);

    Network net(net_st);

    //net.init_all();
    net.load_all();

    //net.train_epoch(train, 200, 5, 5);

    //net.train_epoch_with_regulization(train, 100, 5, 5);

    //evalutate best performance on test sets
    /*double correct_rate, error;
    ofstream out("../../record/test_record.txt", ios::app);
    net.best_performance_on_imagelist(test1, correct_rate, error);
    out << "test1 " << correct_rate << " " << error << endl;
    net.best_performance_on_imagelist(test2, correct_rate, error);
    out << "test2 " << correct_rate << " " << error << endl;
    out.close();

    system("pause");*/

    char* filename1 = (char*) malloc(sizeof(char) * 200);
    //printf("Please enter a path of an existing image:\n");
    //scanf("%s", filename1);

    //printf("\n");

    if (argc == 1)
        cout << "Error!" << endl;
    else
        net.real_predict(argv[1]);

    return 0;
}