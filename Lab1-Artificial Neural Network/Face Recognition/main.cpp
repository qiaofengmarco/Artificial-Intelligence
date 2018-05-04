#include "pack.h"
#include "time.h"
#include "image_processing.hpp"
#include "pgmimage.hpp"
#include "network.hpp"

int main(int argc, char* argv[])
{

    IMAGELIST *train;//, *test1, *test2;
    train = imgl_alloc();
    //test1 = imgl_alloc();
    //test2 = imgl_alloc();
   
    imgl_load_images_from_textfile(train, "../all_train.list");
    //imgl_load_images_from_textfile(test1, "../all_test1.list");
    //imgl_load_images_from_textfile(test2, "../all_test2.list");

    vector<int> net_st;
    int image_size = ROWS(train->list[0]) * COLS(train->list[0]);
    net_st.push_back(image_size);
    net_st.push_back(20);
    net_st.push_back(20);

    Network net(net_st);
    net.load_all();

    //net.init_all();
    //net.train_epoch(train, 500, 25, 10);

    //training
    //net.train_epoch_with_regulization(train, 1500, 25, 10);

    //evalutate best performance on test sets
    /*double correct_rate, error;
    ofstream out("../../record/test_record.txt", ios::app);
    net.best_performance_on_imagelist(test1, correct_rate, error);
    out << "test1 " << correct_rate << " " << error << endl;
    net.best_performance_on_imagelist(test2, correct_rate, error);
    out << "test2 " << correct_rate << " " << error << endl;
    out.close();*/

    char* filename1 = (char*) malloc(sizeof(char) * 200);
    //printf("Please enter a path of an existing image:\n");
    //scanf("%s", filename1);

    //printf("\n");
 
    if (argc == 1)
        cout << "Error!" << endl;
    else
        net.real_predict(argv[1]);

    //system("pause");
    return 0;
}