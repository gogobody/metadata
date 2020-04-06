//
// Created by gogobody on 2020/4/1.
//

#ifndef METADATA_OTHER_H
#define METADATA_OTHER_H

#include <dfs_array.h>

typedef struct conf_server_s conf_server_t;

struct conf_server_s
{
    int      daemon;
    int      worker_n;
    array_t  bind_for_cli;
    array_t  bind_for_dn;
    uint32_t connection_n;
    string_t error_log;
    string_t coredump_dir;
    string_t pid_file;
    uint32_t log_level;
    uint32_t recv_buff_len;
    uint32_t send_buff_len;
    uint32_t max_tqueue_len;
    string_t my_paxos; //当前运行节点的IP/PORT参数
    string_t ot_paxos;
    string_t editlog_dir;
    string_t fsimage_dir;
    uint32_t paxos_group_num;
    uint32_t checkpoint_num;
    uint64_t index_num;
    uint32_t dn_timeout;
};


typedef struct cycle_s cycle_t;

struct cycle_s
{
    void      *sconf; // server conf
    pool_t    *pool;
    log_t     *error_log;
    array_t    listening_for_cli;
    array_t    listening_for_dn;
    string_t   conf_file;
    string_t   admin; // suserid
    uint64_t   namespace_id;
};

static cycle_t *dfs_cycle;

#endif //METADATA_OTHER_H
