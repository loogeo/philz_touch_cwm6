#ifndef NANDROID_H
#define NANDROID_H

int nandroid_main(int argc, char** argv);
int nandroid_backup(const char* backup_path);
int nandroid_restore(const char* backup_path, int restore_boot, int restore_system, int restore_data, int restore_cache, int restore_sdext, int restore_wimax);
void nandroid_dedupe_gc(const char* blob_dir);
void nandroid_force_backup_format(const char* fmt);
unsigned nandroid_get_default_backup_format();

#define NANDROID_BACKUP_FORMAT_FILE "/sdcard/clockworkmod/.default_backup_format"
#define NANDROID_BACKUP_FORMAT_TAR 0
#define NANDROID_BACKUP_FORMAT_DUP 1


/**********************************/
/* Custom nandroid + TWRP backup  */
/*      Written by PhilZ @xda     */
/*    For PhilZ Touch Recovery    */
/*    Keep this credits header    */
/**********************************/

#define EFS_BACKUP_PATH "clockworkmod/custom_backup/.efs_backup"
#define MODEM_BIN_PATH "clockworkmod/custom_backup/.modem_bin"
#define CUSTOM_BACKUP_PATH "clockworkmod/custom_backup"
#define TWRP_BACKUP_PATH "TWRP/BACKUPS"
extern int twrp_backup_mode;
int gen_twrp_md5sum(const char* backup_path);
int check_twrp_md5sum(const char* backup_path);
int twrp_backup(const char* backup_path);
int twrp_restore(const char* backup_path);

#define RAW_IMG_FILE 1
#define RAW_BIN_FILE 2
#define RESTORE_EFS_TAR 1
#define RESTORE_EFS_IMG 2

int custom_backup_raw_handler(const char* backup_path, const char* root);
int custom_restore_raw_handler(const char* backup_path, const char* root);
extern int is_custom_backup;
extern int backup_boot;
extern int backup_recovery;
extern int backup_system;
extern int backup_preload;
extern int backup_data;
extern int backup_cache;
extern int backup_sdext;
extern int backup_wimax;
extern int backup_efs;
extern int backup_modem;

//toggle nandroid compression
#define TAR_GZ_LOW 3
#define TAR_GZ_MEDIUM 6
#define TAR_GZ_HIGH 9
#define TAR_FORMAT 0
extern int compression_value;
extern int enable_md5sum;
extern int nandroid_add_preload;

//option to reboot after user initiated nandroid operations
extern int reboot_after_nandroid;

// support .android_secure on external storage
extern int android_secure_ext;
int get_android_secure_path();

//----------------------------- End Custom nandroid + TWRP backup by PhilZ

#endif
