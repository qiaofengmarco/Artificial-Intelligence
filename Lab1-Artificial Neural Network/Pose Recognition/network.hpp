/*
******************************************************************
* Southeast University Artificial Intelligence Course Project
*
* Author: Qiaofeng Marco LIU
*
* Contact Info: qiaofengmarco@outlook.com
******************************************************************
*/

#ifndef MY_NETWORK_HPP
#define MY_NETWORK_HPP

#include "pack.h"
#include "activator.hpp"
#include "pgmimage.hpp"
#include "image_processing.hpp"

#define BIGRND 0x7fffffff

class Network {
public:
    
    double learning_rate = 0.11, momentum = 0.95, ***w, ***dw, **b, **net, ***global_dw, **global_db, **sigma, ***best_w, **best_b, ***v, **vb;
    int layers, *net_struct;

	/*

    layers: layers in the network
    
	net_struct: the network's structure ( There are net_struct[i] nodes in the ith layer. ) 0 ~ layers-1

	w (weights): 1d: layer id (0 for the first hidden unit) 0 ~ layers - 2
                 2d: node id in the previous layer
                 3d: node id in the current layer

    dw, global_dw: similar to weights

    net: 1d: layer id (0 for the first hidden unit) 0 ~ layers - 2
         2d: node id in the current layer

    sigma: 1d: layer id (0 for the first hidden unit) 0 ~ layers - 2
           2d: node id in the current layer

    b: 1d: layer id (0 for the first hidden unit) 0 ~ layers - 2
       2d: node id in the current layer

	*/

    Network() { init_seed(102194); }
    Network(vector<int> net_struct1) {

        init_seed(102194); //magic

        layers = net_struct1.size();

        net_struct = new int[layers];
        for(int i = 0; i < layers; i++) {
            net_struct[i] = net_struct1[i];
        }


        w = new double**[layers - 1];
        v = new double**[layers - 1];
        best_w = new double**[layers - 1];
        global_dw = new double**[layers - 1];
        dw = new double**[layers - 1];

        b = new double*[layers - 1];
        vb = new double*[layers - 1];
        best_b = new double*[layers - 1];
        global_db = new double*[layers - 1];

        net = new double*[layers - 1];
        sigma = new double*[layers - 1];

        for(int i = 0; i < layers - 1; i++) {
            b[i] = new double[net_struct[i + 1]];
            vb[i] = new double[net_struct[i + 1]];
            best_b[i] = new double[net_struct[i + 1]];
            global_db[i] = new double[net_struct[i + 1]];
            for (int k = 0; k < net_struct[i + 1]; k++) {
                global_db[i][k] = 0;
                vb[i][k] = 0;
            }
            sigma[i] = new double[net_struct[i + 1]];
            net[i] = new double[net_struct[i + 1]];
            w[i] = new double*[net_struct[i]];
            v[i] = new double*[net_struct[i]];
            best_w[i] = new double*[net_struct[i]];
            global_dw[i] = new double*[net_struct[i]];
            dw[i] = new double*[net_struct[i]];
            for(int j = 0; j < net_struct[i]; j++) {
                w[i][j] = new double[net_struct[i + 1]];
                v[i][j] = new double[net_struct[i + 1]];
                best_w[i][j] = new double[net_struct[i + 1]];
                global_dw[i][j] = new double[net_struct[i + 1]];
                for (int k = 0; k < net_struct[i + 1]; k++) {
                    global_dw[i][j][k] = 0;
                    v[i][j][k] = 0;
                }
                dw[i][j] = new double[net_struct[i + 1]];;
            }
        }
    }
    void build_net(vector<int> net_struct1) {

        init_seed(102194); //magic

        layers = net_struct1.size();

        net_struct = new int[layers];
        for (int i = 0; i < layers; i++) {
            net_struct[i] = net_struct1[i];
        }


        w = new double**[layers - 1];
        v = new double**[layers - 1];
        best_w = new double**[layers - 1];
        global_dw = new double**[layers - 1];
        dw = new double**[layers - 1];

        b = new double*[layers - 1];
        vb = new double*[layers - 1];
        best_b = new double*[layers - 1];
        global_db = new double*[layers - 1];

        net = new double*[layers - 1];
        sigma = new double*[layers - 1];

        for (int i = 0; i < layers - 1; i++) {
            b[i] = new double[net_struct[i + 1]];
            vb[i] = new double[net_struct[i + 1]];
            best_b[i] = new double[net_struct[i + 1]];
            global_db[i] = new double[net_struct[i + 1]];
            for (int k = 0; k < net_struct[i + 1]; k++) {
                global_db[i][k] = 0;
                vb[i][k] = 0;
            }
            sigma[i] = new double[net_struct[i + 1]];
            net[i] = new double[net_struct[i + 1]];
            w[i] = new double*[net_struct[i]];
            v[i] = new double*[net_struct[i]];
            best_w[i] = new double*[net_struct[i]];
            global_dw[i] = new double*[net_struct[i]];
            dw[i] = new double*[net_struct[i]];
            for (int j = 0; j < net_struct[i]; j++) {
                w[i][j] = new double[net_struct[i + 1]];
                v[i][j] = new double[net_struct[i + 1]];
                best_w[i][j] = new double[net_struct[i + 1]];
                global_dw[i][j] = new double[net_struct[i + 1]];
                for (int k = 0; k < net_struct[i + 1]; k++) {
                    global_dw[i][j][k] = 0;
                    v[i][j][k] = 0;
                }
                dw[i][j] = new double[net_struct[i + 1]];;
            }
        }
    }

    void predict(double *x, double **result) {
        
        //first layer, for net in layer 1 (net[0])
        for (int now = 0; now < net_struct[1]; now++) {
            net[0][now] = b[0][now];
            for (int pre = 0; pre < net_struct[0]; pre++) {
                net[0][now] += w[0][pre][now] * x[pre];
            }
        }
        
        for (int lys = 1; lys < layers - 1; lys++) {
            for (int now = 0; now < net_struct[lys + 1]; now++) {
                net[lys][now] = b[lys][now];
                for (int pre = 0; pre < net_struct[lys]; pre++) {
                    net[lys][now] += w[lys][pre][now] * __sigmoid(net[lys - 1][pre]);
                }
            }
        }
        
        //for output unit, use softmax
        double sum = 0;
        for (int i = 0; i < net_struct[layers - 1]; i++) {
            sum += exp(net[layers - 2][i]);
        }
        for (int i = 0; i < net_struct[layers - 1]; i++) {
            result[0][i] = exp(net[layers - 2][i]) / sum;
        }

    }

    void best_predict(double *x, double **result) {

        //first layer, for net in layer 1 (net[0])
        for (int now = 0; now < net_struct[1]; now++) {
            net[0][now] = best_b[0][now];
            for (int pre = 0; pre < net_struct[0]; pre++) {
                net[0][now] += best_w[0][pre][now] * x[pre];
            }
        }

        for (int lys = 1; lys < layers - 1; lys++) {
            for (int now = 0; now < net_struct[lys + 1]; now++) {
                net[lys][now] = best_b[lys][now];
                for (int pre = 0; pre < net_struct[lys]; pre++) {
                    net[lys][now] += best_w[lys][pre][now] * __sigmoid(net[lys - 1][pre]);
                }
            }
        }

        //for output unit, use softmax
        double sum = 0;
        for (int i = 0; i < net_struct[layers - 1]; i++) {
            sum += exp(net[layers - 2][i]);
        }
        for (int i = 0; i < net_struct[layers - 1]; i++) {
            result[0][i] = exp(net[layers - 2][i]) / sum;
        }
    }
    
    void back_propagation(double *x, double *correct) {

        double **result, sigmoid_temp;
        result = (double**) malloc(sizeof(double*));
        result[0] = (double*) malloc(sizeof(double) * net_struct[layers - 1]);

        //forward pass
        predict(x, result);
        
        //machine learning p103, eq 4.27
        //for output unit
        for (int now = 0; now < net_struct[layers - 1]; now++) {

            //computing sigma
            //this time, use log-likelihood loss function
            sigma[layers - 2][now] = correct[now] - result[0][now];
            global_db[layers - 2][now] += sigma[layers - 2][now];

            for (int pre = 0; pre < net_struct[layers - 2]; pre++) {
                dw[layers - 2][pre][now] = sigma[layers - 2][now] * __sigmoid(net[layers - 3][pre]);
                global_dw[layers - 2][pre][now] += dw[layers - 2][pre][now];
            }

        }
        
        //machine learning p103, eq 4.28
        for (int lys = layers - 3; lys >= 0; lys--) {
            for (int now = 0; now < net_struct[lys + 1]; now++) {

                sigmoid_temp = __delta_sigmoid(net[lys][now]);
                
                //computing sigma
                sigma[lys][now] = 0;
                for (int post = 0; post < net_struct[lys + 2]; post++)
                    sigma[lys][now] += sigmoid_temp * sigma[lys + 1][post] * w[lys + 1][now][post];
                global_db[lys][now] += sigma[lys][now];
                
                if (lys >= 1) {
                    for(int pre = 0; pre < net_struct[lys]; pre++) {
                        dw[lys][pre][now] = sigma[lys][now] * __sigmoid(net[lys - 1][pre]);
                        global_dw[lys][pre][now] += dw[lys][pre][now];
                    }
                }
                else if (lys == 0) {
                    for(int pre = 0; pre < net_struct[lys]; pre++) {
                        dw[lys][pre][now] = sigma[lys][now] * x[pre];
                        global_dw[lys][pre][now] += dw[lys][pre][now];
                    }
                }
            }
        }
        free(result);
        result = NULL;

    }
    
    void update_best() {
        for (int lys = 0; lys < layers - 1; lys++) {
            for (int now = 0; now < net_struct[lys + 1]; now++) {
                best_b[lys][now] = b[lys][now];
                for (int pre = 0; pre < net_struct[lys]; pre++) {
                    best_w[lys][pre][now] = w[lys][pre][now];
                }
            }
        }
    }

    void recover() {
        for (int lys = 0; lys < layers - 1; lys++) {
            for (int now = 0; now < net_struct[lys + 1]; now++) {
                b[lys][now] = best_b[lys][now];
                for (int pre = 0; pre < net_struct[lys]; pre++) {
                    w[lys][pre][now] = best_w[lys][pre][now];
                }
            }
        }
    }

    void update_all(IMAGELIST* train, int m, double &best_error, double &best_correct_rate) {

        double error, temp, correct_rate, temp1;

        for (int lys = 0; lys < layers - 1; lys++) {
            for (int now = 0; now < net_struct[lys + 1]; now++) {
                temp1 = vb[lys][now] + (learning_rate * global_db[lys][now]) / (double) m;
                b[lys][now] += temp1;
                vb[lys][now] = momentum * temp1;
                global_db[lys][now] = temp1;
                for (int pre = 0; pre < net_struct[lys]; pre++) {
                    temp = v[lys][pre][now] + (learning_rate * global_dw[lys][pre][now]) / (double) m;
                    w[lys][pre][now] += temp; 
                    v[lys][pre][now] = momentum * temp;
                    global_dw[lys][pre][now] = temp;
                }
            }
        }

        performance_on_imagelist(train, correct_rate, error);

        ofstream record;
        record.open("../record/training_record.txt", ios::app);
        record << correct_rate << " " << error << endl;
        record.close();

        if ((error < best_error) && (correct_rate >= best_correct_rate)) {
            update_best();
            best_error = error;
            best_correct_rate = correct_rate;
        }

    }

    void update_all_with_regulization(IMAGELIST* train, int m, double &best_error, double &best_correct_rate) {

        double error, temp, temp1, correct_rate, regulization_factor = 0.00001;

        for (int lys = 0; lys < layers - 1; lys++) {
            for (int now = 0; now < net_struct[lys + 1]; now++) {
                temp1 = vb[lys][now] + (learning_rate * global_db[lys][now]) / (double) m;
                b[lys][now] -= b[lys][now] * regulization_factor;
                b[lys][now] += temp1;
                vb[lys][now] = momentum * temp1;
                global_db[lys][now] = temp1;
                for (int pre = 0; pre < net_struct[lys]; pre++) {
                    temp = v[lys][pre][now] + (learning_rate * global_dw[lys][pre][now]) / (double) m;
                    w[lys][pre][now] -= w[lys][pre][now] * regulization_factor;
                    w[lys][pre][now] += temp;
                    v[lys][pre][now] = momentum * temp;
                    global_dw[lys][pre][now] = temp;
                }
            }
        }

        performance_on_imagelist(train, correct_rate, error);

        ofstream record;
        record.open("../record/training_record.txt", ios::app);
        record << correct_rate << " " << error << endl;
        record.close();

        if ((error < best_error) && (best_correct_rate > correct_rate)) {
            update_best();
            best_error = error;
            best_correct_rate = correct_rate;
        }

    }

    void init_seed(unsigned int a) {
        srand(a);
    }

    double drnd() {
        return ((double) rand() / (double)BIGRND);
    }


    double dpn1() {
        return ((drnd() * 2.0) - 1.0);
    }

    void init_all() {
        for(int lys = 0; lys < layers - 1; lys++) {
            for(int now = 0; now < net_struct[lys + 1]; now++) {
                b[lys][now] = dpn1() * 0.5;
                best_b[lys][now] = b[lys][now];
                vb[lys][now] = 0.0;
                for(int pre = 0; pre < net_struct[lys]; pre++) {
                    w[lys][pre][now] = dpn1();
                    best_w[lys][pre][now] = w[lys][pre][now];
                    v[lys][pre][now] = 0.0;
                }
            }
        }
    }

    void save_all() {
        FILE* fp;
        fp = fopen("../network/net", "wb");
        for (int lys = 0; lys < layers - 1; lys++) { 
            for (int pre = 0; pre < net_struct[lys]; pre++) {
                for (int now = 0; now < net_struct[lys + 1]; now++) {
                    fwrite(&best_w[lys][pre][now], sizeof(double), 1, fp);
                }
            }
        }
        for (int lys = 0; lys < layers - 1; lys++) {
            for (int now = 0; now < net_struct[lys + 1]; now++) {
                fwrite(&best_b[lys][now], sizeof(double), 1, fp);
            }
        }
        fclose(fp);
    }

    void load_all() {
        FILE* fp;
        fp = fopen("../network/net", "rb");
        for (int lys = 0; lys < layers - 1; lys++)
            for (int pre = 0; pre < net_struct[lys]; pre++) {
                for (int now = 0; now < net_struct[lys + 1]; now++) {
                    fread(&w[lys][pre][now], sizeof(double), 1, fp);
                    best_w[lys][pre][now] = w[lys][pre][now];
                    v[lys][pre][now] = 0.0;
                }
            }
        for (int lys = 0; lys < layers - 1; lys++) {
            for (int now = 0; now < net_struct[lys + 1]; now++) {
                fread(&b[lys][now], sizeof(double), 1, fp);
                best_b[lys][now] = b[lys][now];
                vb[lys][now] = 0.0;
            }
        }
        fclose(fp);
    }
    
    bool evaluate_performance(double &error, double* input, double* target) {

        double **result;

        result = new double*[1];
        result[0] = new double[net_struct[layers - 1]];

        predict(input, result);

        //loss function: negative log-likelihood
        //L = -1 * sum(target_i * log(output_i));
        
        error = 0.0;
        for (int i = 0; i < net_struct[layers - 1]; i++) {
            error += -1 * target[i] * log(result[0][i]);
        }
        
        double max = result[0][0];
        int max_index = 0;
        for (int i = 1; i < net_struct[layers - 1]; i++) {
            if (max < result[0][i]) {
                max = result[0][i];
                max_index = i;
            }
        }
        return (target[max_index] > 0.5);
    }
    
    bool evaluate_best_performance(double &error, double* input, double* target) {


        double **result;

        result = new double*[1];
        result[0] = new double[net_struct[layers - 1]];

        best_predict(input, result);

        //loss function: negative log-likelihood
        //L = -1 * sum(target_i * log(output_i));
        
        error = 0.0;
        for (int i = 0; i < net_struct[layers - 1]; i++) {
            error += -1 * target[i] * log(result[0][i]);
        }
        
        double max = result[0][0];
        int max_index = 0;
        for (int i = 1; i < net_struct[layers - 1]; i++) {
            if (max < result[0][i]) {
                max = result[0][i];
                max_index = i;
            }
        }
        return (target[max_index] > 0.5);
    }

    void performance_on_imagelist(IMAGELIST* il, double &correct_rate, double &error) {
        double val;
        int correct, n;
        double **input, **target;
        target = (double**) malloc(sizeof(double*));
        input = (double**) malloc(sizeof(double*));
        target[0] = (double*) malloc(sizeof(double) * net_struct[layers - 1]);
        input[0] = (double*) malloc(sizeof(double) * net_struct[0]);
        error = 0.0;
        correct = 0;
        n = il->n;
        if (n > 0) {
            for (int i = 0; i < n; i++) {
                image_to_input(il->list[i], input);
                load_man_target(il->list[i], target);
                if (evaluate_performance(val, input[0], target[0]))  {
                    correct++;
                    //printf("%.3f\n", val);
                }
                else {
                    //
                }
                error += val;
            }
        }
        error = error / (double) n;
        correct_rate = ((double) correct / (double) (n));
        cout << correct_rate << " " << error << endl; 
        free(input);
        free(target);
        input = NULL;
        target = NULL;
    }

    void best_performance_on_imagelist(IMAGELIST* il, double &correct_rate, double &error) {
        double val;
        int correct, n;
        double **input, **target;
        target = (double**) malloc(sizeof(double*));
        input = (double**) malloc(sizeof(double*));
        target[0] = (double*) malloc(sizeof(double) * net_struct[layers - 1]);
        input[0] = (double*) malloc(sizeof(double) * net_struct[0]);
        error = 0.0;
        correct = 0;
        n = il->n;
        if (n > 0) {
            for (int i = 0; i < n; i++) {
                image_to_input(il->list[i], input);
                load_man_target(il->list[i], target);
                if (evaluate_best_performance(val, input[0], target[0]))  {
                    correct++;
                    //printf("%.3f\n", val);
                }
                else {
                    //
                }
                error += val;
            }
        }
        error = error / (double) n;
        correct_rate = ((double) correct / (double) (n));
        cout << correct_rate << " " << error << endl;
        free(input);
        free(target);
        input = NULL;
        target = NULL;
    }

    void train_list(IMAGELIST* train, int batch) {

        int n = train->n;
        double **input, **target, best_error = 1000, best_correct_rate = 0.0;
        target = (double**) malloc(sizeof(double*));
        input = (double**) malloc(sizeof(double*));
        target[0] = (double*) malloc(sizeof(double) * net_struct[layers - 1]);
        input[0] = (double*) malloc(sizeof(double) * net_struct[0]);
        if (n > 0) {
            performance_on_imagelist(train, best_correct_rate, best_error);
            for (int i = 0; i < n; i++) {
                image_to_input(train->list[i], input);
                load_man_target(train->list[i], target);
                back_propagation(input[0], target[0]);
                if ((i % batch == 0) && (i >= batch)) {
                    update_all(train, batch, best_error, best_correct_rate);
                }
            }
        }
        free(input);
        free(target);
        input = NULL;
        target = NULL;
    }

    void train_list_with_regulization(IMAGELIST* train, int batch) {

        int n = train->n;
        double **input, **target, best_error = 1000, best_correct_rate = 0.0;
        target = (double**) malloc(sizeof(double*));
        input = (double**) malloc(sizeof(double*));
        target[0] = (double*) malloc(sizeof(double) * net_struct[layers - 1]);
        input[0] = (double*) malloc(sizeof(double) * net_struct[0]);
        if (n > 0) {
            performance_on_imagelist(train, best_correct_rate, best_error);
            for (int i = 0; i < n; i++) {
                image_to_input(train->list[i], input);
                load_man_target(train->list[i], target);
                back_propagation(input[0], target[0]);
                if ((i % batch == 0) && (i >= batch)) {
                    update_all_with_regulization(train, batch, best_error, best_correct_rate);
                }
            }
        }
        free(input);
        free(target);
        input = NULL;
        target = NULL;
    }

    void train_epoch(IMAGELIST* train, double epoch, int batch, int save_signal) {
        for (int i = 0; i < epoch; i++) {
            cout << "epoch: " << i + 1 << endl;
            train_list(train, batch);
            if ((i == epoch - 1) || ((i % save_signal == 0) && (i >= save_signal)))
                save_all();
        }
    }

    void train_epoch_with_regulization(IMAGELIST* train, double epoch, int batch, int save_signal) {
        for (int i = 0; i < epoch; i++) {
            cout << "epoch: " << i + 1 << endl;
            train_list_with_regulization(train, batch);
            if ((i == epoch - 1) || ((i % save_signal == 0) && (i >= save_signal)))
                save_all();
        }
    }

    ~Network() {
        delete[] w;
        delete[] b;
        delete[] dw;
        delete[] net;
        delete[] global_db;
        delete[] global_dw;
        delete[] sigma;
        delete[] best_b;
        delete[] best_w;
        delete[] v;
    }
};
#endif