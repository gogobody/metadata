#include <iostream>
#include <cstring>
#include "file_index.h"
#include "core/dfs_types.h"
#include "core/dfs_string.h"
using namespace std;
int mkdir_(char* key){
    fi_inode_t fin;
    memset(&fin, 0x00, sizeof(fi_inode_t));
    fin.is_directory = DFS_TRUE;
    strcpy(fin.key,key);

    update_fi_mkdir(&fin);
    return 0;
}

int main() {
    uchar_t names[PATH_LEN][PATH_LEN];
    uchar_t path[PATH_LEN] = "/test/a";

    int names_sz = get_path_names(path, names);
    printf("%d\n",names_sz);

    uchar_t keys[PATH_LEN][PATH_LEN];
    get_path_keys(names, names_sz, keys); // 把每一级目录都 encode方便查找是否已经创建过

    // init
    nn_file_index_worker_init(100000);

    // 创建多级目录
    for(int i =0;i<names_sz-1;i++){
        mkdir_(reinterpret_cast<char *>(keys[i]));
    }
    fi_inode_t        *finodes[PATH_LEN];
    int                parent_index = 0;

    // 找到
    parent_index = get_path_inodes(keys, names_sz, finodes);
    cout<<parent_index<<endl;
    return 0;
}
