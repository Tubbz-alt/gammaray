#ifndef XRAY_DISK_ANALYZER_EXT4_H
#define XRAY_DISK_ANALYZER_EXT4_H

/* Thanks: http://git.kernel.org/?p=linux/kernel/git/torvalds/linux.git;a=blob_plain;f=fs/ext4/ext4.h;hb=10c63c9aec648402f593b6c883ca247ece7b2af9 */

#include <inttypes.h>
#include <stdint.h>

#define SECTOR_SIZE 512
#define EXT4_SUPERBLOCK_OFFSET 1024

struct ext4_superblock
{
    uint32_t s_inodes_count;
    uint32_t s_blocks_count_lo;
    uint32_t s_r_blocks_count_lo;
    uint32_t s_free_blocks_count_lo;
    uint32_t s_free_inodes_count;
    uint32_t s_first_data_block;
    uint32_t s_log_block_size;
    uint32_t s_log_cluster_size;
    uint32_t s_blocks_per_group;
    uint32_t s_clusters_per_group;
    uint32_t s_inodes_per_group;
    uint32_t s_mtime;
    uint32_t s_wtime;
    uint16_t s_mnt_count;
    uint16_t s_max_mnt_count;
    uint16_t s_magic;
    uint16_t s_state;
    uint16_t s_errors;
    uint16_t s_minor_rev_level;
    uint32_t s_lastcheck;
    uint32_t s_checkinterval;
    uint32_t s_creator_os;
    uint32_t s_rev_level;
    uint16_t s_def_resuid;
    uint16_t s_def_resgid;
    uint32_t s_first_ino;
    uint16_t s_inode_size;
    uint16_t s_block_group_nr;
    uint32_t s_feature_compat;
    uint32_t s_feature_incompat;
    uint32_t s_feature_ro_compat;
    uint8_t  s_uuid[16];
    uint8_t  s_volume_name[16];
    uint8_t  s_last_mounted[64];
    uint32_t s_algorithm_usage_bitmap;
    uint8_t  s_prealloc_blocks;
    uint8_t  s_prealloc_dir_blocks;
    uint16_t s_reserved_gdt_blocks;
    uint8_t  s_journal_uuid[16];
    uint32_t s_journal_inum;
    uint32_t s_journal_dev;
    uint32_t s_last_orphan;
    uint32_t s_hash_seed[4];
    uint8_t  s_def_hash_version;
    uint8_t  s_jnl_backup_type;
    uint16_t s_desc_size;
    uint32_t s_default_mount_opts;
    uint32_t s_first_meta_bg;
    uint32_t s_mkfs_time;
    uint32_t s_jnl_blocks[17];
    uint32_t s_blocks_count_hi;
    uint32_t s_r_blocks_count_hi;
    uint32_t s_free_blocks_count_hi;
    uint16_t s_min_extra_isize;
    uint16_t s_want_extra_isize;
    uint32_t s_flags;
    uint16_t s_raid_stride;
    uint16_t s_mmp_update_interval;
    uint64_t s_mmp_block;
    uint32_t s_raid_stripe_width;
    uint8_t  s_log_groups_per_flex;
    uint8_t  s_checksum_type;
    uint16_t s_reserved_pad;
    uint64_t s_kbytes_written;
    uint32_t s_snapshot_inum;
    uint32_t s_snapshot_id;
    uint64_t s_snapshot_r_blocks_count;
    uint32_t s_snapshot_list;
    uint32_t s_error_count;
    uint32_t s_first_error_time;
    uint32_t s_first_error_ino;
    uint64_t s_first_error_block;
    uint8_t  s_first_error_func[32];
    uint32_t s_first_error_line;
    uint32_t s_last_error_time;
    uint32_t s_last_error_ino;
    uint32_t s_last_error_line;
    uint64_t s_last_error_block;
    uint8_t  s_last_error_func[32];
    uint8_t  s_mount_opts[64];
    uint32_t s_usr_quota_inum;
    uint32_t s_grp_quota_inum;
    uint32_t s_overhead_clusters;
    uint32_t s_reserved[108];
    uint32_t s_checksum;
} __attribute__((packed));

struct ext4_block_group_descriptor
{
    uint32_t bg_block_bitmap_lo;
    uint32_t bg_inode_bitmap_lo;
    uint32_t bg_inode_table_lo;
    uint16_t bg_free_blocks_count_lo;
    uint16_t bg_free_inodes_count_lo;
    uint16_t bg_used_dirs_count_lo;
    uint16_t bg_flags;
    uint32_t bg_exclude_bitmap_lo;
    uint16_t bg_block_bitmap_csum_lo;
    uint16_t bg_inode_bitmap_csum_lo;
    uint16_t bg_itable_unused_lo;
    uint16_t bg_checksum;
    uint32_t bg_block_bitmap_hi;
    uint32_t bg_inode_bitmap_hi;
    uint32_t bg_inode_table_hi;
    uint16_t bg_free_blocks_count_hi;
    uint16_t bg_free_inodes_count_hi;
    uint16_t bg_used_dirs_count_hi;
    uint16_t bg_itable_unused_hi;
    uint32_t bg_exclude_bitmap_hi;
    uint16_t bg_block_bitmap_csum_hi;
    uint16_t bg_inode_bitmap_csum_hi;
    uint32_t bg_reserved;
} __attribute__((packed));

struct ext4_inode
{
    uint16_t i_mode;
    uint16_t i_uid;
    uint32_t i_size_lo;
    uint32_t i_atime;
    uint32_t i_ctime;
    uint32_t i_mtime;
    uint32_t i_dtime;
    uint16_t i_gid;
    uint16_t i_links_count;
    uint32_t i_blocks_lo;
    uint32_t i_flags;
    uint8_t  i_osd1[4];
    uint32_t i_block[15];
    uint32_t i_generation;
    uint32_t i_file_acl_lo;
    uint32_t i_size_high;
    uint32_t i_obso_faddr;
    uint8_t  i_osd2[12];
    uint16_t i_extra_isize;
    uint16_t i_checksum_hi;
    uint32_t i_ctime_extra;
    uint32_t i_mtime_extra;
    uint32_t i_atime_extra;
    uint32_t i_crtime;
    uint32_t i_crtime_extra;
    uint32_t i_version_hi;
} __attribute__((packed));

int ext4_print_superblock(struct ext4_superblock superblock);
int ext4_print_block_group_descriptor(struct ext4_block_group_descriptor);
int ext4_print_inode(struct ext4_inode);
int ext4_print_dir_entries(uint8_t* bytes, uint32_t len);
int simple_find(uint32_t inode_table_location,
                FILE* disk, uint32_t inode, char* path_prefix);
int ext4_probe(FILE* disk, int64_t partition_offset,
               struct ext4_superblock* superblock);
int ext4_read_inode(FILE* disk, int64_t partition_offset,
                    struct ext4_superblock superblock, uint32_t inode_num,
                    struct ext4_inode* inode);
int ext4_list_block_groups(FILE* disk, int64_t partition_offset,
                           struct ext4_superblock superblock);
int ext4_list_root_fs(FILE* disk, int64_t partition_offset,
                      struct ext4_superblock superblock, char* prefix);
int ext4_reconstruct_root_fs(FILE* disk, int64_t partition_offset, 
                             struct ext4_superblock superblock, char* prefix,
                             char* copy_prefix);
int ext4_read_block(FILE* disk, int64_t partition_offset, 
                    struct ext4_superblock superblock, uint64_t block_num, 
                    uint8_t* buf);
int ext4_print_block(uint8_t* buf, uint32_t block_size);
uint32_t ext4_block_size(struct ext4_superblock superblock);
int ext4_print_sectormap(FILE* disk, int64_t partition_offset,
                         struct ext4_superblock superblock);
int64_t ext4_sector_from_block(uint32_t block);
char* ext4_last_mount_point(struct ext4_superblock* superblock);
int ext4_serialize_fs(struct ext4_superblock* superblock,
                      char* mount_point, FILE* serializef);
int ext4_serialize_bgds(FILE* disk, int64_t partition_offset,
                        struct ext4_superblock* superblock, FILE* serializef);
int ext4_serialize_fs_tree(FILE* disk, int64_t partition_offset,
                           struct ext4_superblock* superblock, char* prefix,
                           FILE* serializef);
#endif