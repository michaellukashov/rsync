/* This file is automatically generated with "make proto". DO NOT EDIT */

int allow_access(const char *addr, const char **host_ptr, int i);
void free_acl(stat_x *sxp);
int get_acl(const char *fname, stat_x *sxp);
void send_acl(int f, stat_x *sxp);
void receive_acl(int f, struct file_struct *file);
void cache_tmp_acl(struct file_struct *file, stat_x *sxp);
void uncache_tmp_acls(void);
int set_acl(const char *fname, const struct file_struct *file, stat_x *sxp, mode_t new_mode);
void match_acl_ids(void);
int default_perms_for_dir(const char *dir);
void base64_encode(const char *buf, int len, char *out, int pad);
char *auth_server(int f_in, int f_out, int module, const char *host,
		  const char *addr, const char *leader);
void auth_client(int fd, const char *user, const char *challenge);
char *get_backup_name(const char *fname);
int make_backup(const char *fname, BOOL prefer_rename);
void write_stream_flags(int fd);
void read_stream_flags(int fd);
void check_batch_flags(void);
void open_batch_files(void);
void write_batch_shell_file(void);
int parse_csum_name(const char *name, int len);
void parse_checksum_choice(int final_call);
int csum_len_for_type(int cst, BOOL flist_csum);
int canonical_checksum(int csum_type);
uint32 get_checksum1(char *buf1, int32 len);
void get_checksum2(char *buf, int32 len, char *sum);
void file_checksum(const char *fname, const STRUCT_STAT *st_p, char *sum);
void sum_init(int csum_type, int seed);
void sum_update(const char *p, int32 len);
int sum_end(char *sum);
struct chmod_mode_struct *parse_chmod(const char *modestr,
				      struct chmod_mode_struct **root_mode_ptr);
int tweak_mode(int mode, struct chmod_mode_struct *chmod_modes);
int free_chmod_mode(struct chmod_mode_struct *chmod_modes);
void close_all(void);
NORETURN void _exit_cleanup(int code, const char *file, int line);
void cleanup_disable(void);
void cleanup_set(const char *fnametmp, const char *fname, struct file_struct *file,
		 int fd_r, int fd_w);
void cleanup_set_pid(pid_t pid);
char *client_addr(int fd);
char *client_name(const char *ipaddr);
int read_proxy_protocol_header(int fd);
int start_socket_client(char *host, int remote_argc, char *remote_argv[],
			int argc, char *argv[]);
int start_inband_exchange(int f_in, int f_out, const char *user, int argc, char *argv[]);
void set_env_num(const char *var, long num);
BOOL namecvt_call(const char *cmd, const char **name_p, id_t *id_p);
int start_daemon(int f_in, int f_out);
int daemon_main(void);
void set_allow_inc_recurse(void);
void parse_compress_choice(int final_call);
struct name_num_item *get_nni_by_name(struct name_num_obj *nno, const char *name, int len);
struct name_num_item *get_nni_by_num(struct name_num_obj *nno, int num);
void validate_choice_vs_env(int ntype, int num1, int num2);
int get_default_nno_list(struct name_num_obj *nno, char *to_buf, int to_buf_len, char dup_markup);
void setup_protocol(int f_out,int f_in);
int claim_connection(char *fname, int max_connections);
enum delret delete_item(char *fbuf, uint16 mode, uint16 flags);
uint16 get_del_for_flag(uint16 mode);
void set_filter_dir(const char *dir, unsigned int dirlen);
void *push_local_filters(const char *dir, unsigned int dirlen);
void pop_local_filters(void *mem);
void change_local_filter_dir(const char *dname, int dlen, int dir_depth);
int name_is_excluded(const char *fname, int name_flags, int filter_level);
int check_filter(filter_rule_list *listp, enum logcode code,
		 const char *name, int name_flags);
const filter_rule *rule_template(uint32 rflags);
void parse_filter_str(filter_rule_list *listp, const char *rulestr,
		     const filter_rule *template, int xflags);
void parse_filter_file(filter_rule_list *listp, const char *fname, const filter_rule *template, int xflags);
char *get_rule_prefix(filter_rule *rule, const char *pat, int for_xfer,
		      unsigned int *plen_ptr);
void send_filter_list(int f_out);
void recv_filter_list(int f_in);
int sparse_end(int f, OFF_T size);
int flush_write_file(int f);
int write_file(int f, int use_seek, OFF_T offset, const char *buf, int len);
int skip_matched(int fd, OFF_T offset, const char *buf, int len);
struct map_struct *map_file(int fd, OFF_T len, int32 read_size, int32 blk_size);
char *map_ptr(struct map_struct *map, OFF_T offset, int32 len);
int unmap_file(struct map_struct *map);
void init_flist(void);
void show_flist_stats(void);
int link_stat(const char *path, STRUCT_STAT *stp, int follow_dirlinks);
int change_pathname(struct file_struct *file, const char *dir, int dirlen);
struct file_struct *make_file(const char *fname, struct file_list *flist,
			      STRUCT_STAT *stp, int flags, int filter_level);
OFF_T get_device_size(int fd, const char *fname);
void unmake_file(struct file_struct *file);
void send_extra_file_list(int f, int at_least);
struct file_list *send_file_list(int f, int argc, char *argv[]);
struct file_list *recv_file_list(int f, int dir_ndx);
void recv_additional_file_list(int f);
int flist_find(struct file_list *flist, struct file_struct *f);
int flist_find_name(struct file_list *flist, const char *fname, int want_dir_match);
int flist_find_ignore_dirness(struct file_list *flist, struct file_struct *f);
void clear_file(struct file_struct *file);
void flist_free(struct file_list *flist);
int f_name_cmp(const struct file_struct *f1, const struct file_struct *f2);
int f_name_has_prefix(const struct file_struct *f1, const struct file_struct *f2);
char *f_name_buf(void);
char *f_name(const struct file_struct *f, char *fbuf);
struct file_list *get_dirlist(char *dirname, int dlen, int flags);
int unchanged_attrs(const char *fname, struct file_struct *file, stat_x *sxp);
void itemize(const char *fnamecmp, struct file_struct *file, int ndx, int statret,
	     stat_x *sxp, int32 iflags, uchar fnamecmp_type,
	     const char *xname);
int unchanged_file(char *fn, struct file_struct *file, STRUCT_STAT *st);
int atomic_create(struct file_struct *file, char *fname, const char *slnk, const char *hlnk,
		  dev_t rdev, stat_x *sxp, int del_for_flag);
void check_for_finished_files(int itemizing, enum logcode code, int check_redo);
void generate_files(int f_out, const char *local_name);
struct hashtable *hashtable_create(int size, int key64);
void hashtable_destroy(struct hashtable *tbl);
void *hashtable_find(struct hashtable *tbl, int64 key, void *data_when_new);
uint32_t hashlittle(const void *key, size_t length);
void init_hard_links(void);
struct ht_int64_node *idev_find(int64 dev, int64 ino);
void idev_destroy(void);
void match_hard_links(struct file_list *flist);
int hard_link_check(struct file_struct *file, int ndx, char *fname,
		    int statret, stat_x *sxp, int itemizing,
		    enum logcode code);
int hard_link_one(struct file_struct *file, const char *fname,
		  const char *oldname, int terse);
void finish_hard_link(struct file_struct *file, const char *fname, int fin_ndx,
		      STRUCT_STAT *stp, int itemizing, enum logcode code,
		      int alt_dest);
int skip_hard_link(struct file_struct *file, struct file_list **flist_p);
void reduce_iobuf_size(xbuf *out, size_t new_size);
void restore_iobuf_size(xbuf *out);
void noop_io_until_death(void);
int send_msg(enum msgcode code, const char *buf, size_t len, int convert);
void send_msg_int(enum msgcode code, int num);
void io_set_sock_fds(int f_in, int f_out);
void set_io_timeout(int secs);
void increment_active_files(int ndx, int itemizing, enum logcode code);
int get_redo_num(void);
int get_hlink_num(void);
void start_filesfrom_forwarding(int fd);
int read_line(int fd, char *buf, size_t bufsiz, int flags);
void read_args(int f_in, char *mod_name, char *buf, size_t bufsiz, int rl_nulls,
	       char ***argv_p, int *argc_p, char **request_p);
BOOL io_start_buffering_out(int f_out);
BOOL io_start_buffering_in(int f_in);
void io_end_buffering_in(BOOL free_buffers);
void io_end_buffering_out(BOOL free_buffers);
void maybe_flush_socket(int important);
void maybe_send_keepalive(time_t now, int flags);
void start_flist_forward(int ndx);
void stop_flist_forward(void);
void wait_for_receiver(void);
unsigned short read_shortint(int f);
int32 read_int(int f);
int32 read_varint(int f);
int64 read_varlong(int f, uchar min_bytes);
int64 read_longint(int f);
void read_buf(int f, char *buf, size_t len);
void read_sbuf(int f, char *buf, size_t len);
uchar read_byte(int f);
int read_vstring(int f, char *buf, int bufsize);
void read_sum_head(int f, struct sum_struct *sum);
void write_sum_head(int f, struct sum_struct *sum);
void io_flush(int flush_type);
void write_shortint(int f, unsigned short x);
void write_int(int f, int32 x);
void write_varint(int f, int32 x);
void write_varlong(int f, int64 x, uchar min_bytes);
void write_longint(int f, int64 x);
void write_bigbuf(int f, const char *buf, size_t len);
void write_buf(int f, const char *buf, size_t len);
void write_sbuf(int f, const char *buf);
void write_byte(int f, uchar c);
void write_vstring(int f, const char *str, int len);
void write_ndx(int f, int32 ndx);
int32 read_ndx(int f);
int read_line_old(int fd, char *buf, size_t bufsiz, int eof_ok);
void io_printf(int fd, const char *format, ...);
void io_start_multiplex_out(int fd);
void io_start_multiplex_in(int fd);
int io_end_multiplex_in(int mode);
int io_end_multiplex_out(int mode);
void start_write_batch(int fd);
void stop_write_batch(void);
void reset_daemon_vars(void);
int lp_load(char *pszFname, int globals_only);
BOOL set_dparams(int syntax_check_only);
int lp_num_modules(void);
int lp_number(char *name);
void log_init(int restart);
void logfile_close(void);
void logfile_reopen(void);
void rwrite(enum logcode code, const char *buf, int len, int is_utf8);
void rprintf(enum logcode code, const char *format, ...);
void rsyserr(enum logcode code, int errcode, const char *format, ...);
void rflush(enum logcode code);
void remember_initial_stats(void);
int log_format_has(const char *format, char esc);
void log_item(enum logcode code, struct file_struct *file, int iflags, const char *hlink);
void maybe_log_item(struct file_struct *file, int iflags, int itemizing, const char *buf);
void log_delete(const char *fname, int mode);
void log_exit(int code, const char *file, int line);
pid_t wait_process(pid_t pid, int *status_ptr, int flags);
int shell_exec(const char *cmd);
void write_del_stats(int f);
void read_del_stats(int f);
int child_main(int argc, char *argv[]);
void start_server(int f_in, int f_out, int argc, char *argv[]);
int client_run(int f_in, int f_out, pid_t pid, int argc, char *argv[]);
void remember_children(UNUSED(int val));
const char *get_panic_action(void);
int main(int argc,char *argv[]);
void match_sums(int f, struct sum_struct *s, struct map_struct *buf, OFF_T len);
void match_report(void);
void limit_output_verbosity(int level);
void reset_output_levels(void);
void negate_output_levels(void);
void option_error(void);
char *alt_dest_opt(int type);
int parse_arguments(int *argc_p, const char ***argv_p);
void server_options(char **args, int *argc_p);
char *check_for_hostspec(char *s, char **host_ptr, int *port_ptr);
int pm_process( char *FileName,
                 BOOL (*sfunc)(char *),
                 BOOL (*pfunc)(char *, char *) );
pid_t piped_child(char **command, int *f_in, int *f_out);
pid_t local_child(int argc, char **argv, int *f_in, int *f_out,
		  int (*child_main)(int, char*[]));
void progress_init(void);
void set_current_file_index(struct file_struct *file, int ndx);
void instant_progress(const char *fname);
void end_progress(OFF_T size);
void show_progress(OFF_T ofs, OFF_T size);
int get_tmpname(char *fnametmp, const char *fname, BOOL make_unique);
int open_tmpfile(char *fnametmp, const char *fname, struct file_struct *file);
int recv_files(int f_in, int f_out, char *local_name);
void setup_iconv(void);
int iconvbufs(iconv_t ic, xbuf *in, xbuf *out, int flags);
void send_protected_args(int fd, char *args[]);
int read_ndx_and_attrs(int f_in, int f_out, int *iflag_ptr, uchar *type_ptr, char *buf, int *len_ptr);
void free_sums(struct sum_struct *s);
mode_t dest_mode(mode_t flist_mode, mode_t stat_mode, int dflt_perms,
		 int exists);
int set_file_attrs(const char *fname, struct file_struct *file, stat_x *sxp,
		   const char *fnamecmp, int flags);
void sig_int(int sig_num);
int finish_transfer(const char *fname, const char *fnametmp,
		    const char *fnamecmp, const char *partialptr,
		    struct file_struct *file, int ok_to_set_time,
		    int overwriting_basis);
struct file_list *flist_for_ndx(int ndx, const char *fatal_error_loc);
const char *who_am_i(void);
void successful_send(int ndx);
void send_files(int f_in, int f_out);
int try_bind_local(int s, int ai_family, int ai_socktype,
		   const char *bind_addr);
int open_socket_out(char *host, int port, const char *bind_addr, int af_hint);
int open_socket_out_wrapped(char *host, int port, const char *bind_addr, int af_hint);
int is_a_socket(int fd);
void start_accept_loop(int port, int (*fn)(int, int));
void set_socket_options(int fd, char *options);
int do_unlink(const char *fname);
int do_symlink(const char *lnk, const char *fname);
ssize_t do_readlink(const char *path, char *buf, size_t bufsiz);
int do_link(const char *old_path, const char *new_path);
int do_lchown(const char *path, uid_t owner, gid_t group);
int do_mknod(const char *pathname, mode_t mode, dev_t dev);
int do_rmdir(const char *pathname);
int do_open(const char *pathname, int flags, mode_t mode);
int do_chmod(const char *path, mode_t mode);
int do_rename(const char *old_path, const char *new_path);
int do_ftruncate(int fd, OFF_T size);
void trim_trailing_slashes(char *name);
int do_mkdir(char *fname, mode_t mode);
int do_mkstemp(char *template, mode_t perms);
int do_stat(const char *fname, STRUCT_STAT *st);
int do_lstat(const char *fname, STRUCT_STAT *st);
int do_fstat(int fd, STRUCT_STAT *st);
OFF_T do_lseek(int fd, OFF_T offset, int whence);
int do_setattrlist_times(const char *fname, STRUCT_STAT *stp);
time_t get_create_time(const char *path);
int set_create_time(const char *path, time_t crtime);
int do_utimensat(const char *fname, STRUCT_STAT *stp);
int do_lutimes(const char *fname, STRUCT_STAT *stp);
int do_utimes(const char *fname, STRUCT_STAT *stp);
int do_utime(const char *fname, STRUCT_STAT *stp);
OFF_T do_fallocate(int fd, OFF_T offset, OFF_T length);
int do_punch_hole(int fd, OFF_T pos, OFF_T len);
int do_open_nofollow(const char *pathname, int flags);
void init_compression_level(void);
void set_compression(const char *fname);
void send_token(int f, int32 token, struct map_struct *buf, OFF_T offset,
		int32 n, int32 toklen);
int32 recv_token(int f, char **data);
void see_token(char *data, int32 toklen);
const char *uid_to_user(uid_t uid);
const char *gid_to_group(gid_t gid);
int user_to_uid(const char *name, uid_t *uid_p, BOOL num_ok);
int group_to_gid(const char *name, gid_t *gid_p, BOOL num_ok);
uid_t match_uid(uid_t uid);
gid_t match_gid(gid_t gid, uint16 *flags_ptr);
const char *add_uid(uid_t uid);
const char *add_gid(gid_t gid);
void send_id_lists(int f);
uid_t recv_user_name(int f, uid_t uid);
gid_t recv_group_name(int f, gid_t gid, uint16 *flags_ptr);
void recv_id_list(int f, struct file_list *flist);
void parse_name_map(char *map, BOOL usernames);
const char *getallgroups(uid_t uid, item_list *gid_list);
void print_rsync_version(enum logcode f);
void usage(enum logcode F);
void daemon_usage(enum logcode F);
const char *rsync_version(void);
const char *default_cvsignore(void);
void set_nonblocking(int fd);
void set_blocking(int fd);
int fd_pair(int fd[2]);
void print_child_argv(const char *prefix, char **cmd);
int set_times(const char *fname, STRUCT_STAT *stp);
int make_path(char *fname, int flags);
int full_write(int desc, const char *ptr, size_t len);
int copy_file(const char *source, const char *dest, int ofd, mode_t mode);
int robust_unlink(const char *fname);
int robust_rename(const char *from, const char *to, const char *partialptr,
		  int mode);
pid_t do_fork(void);
void kill_all(int sig);
int lock_range(int fd, int offset, int len);
int glob_expand(const char *arg, char ***argv_p, int *argc_p, int *maxargs_p);
void glob_expand_module(char *base1, char *arg, char ***argv_p, int *argc_p, int *maxargs_p);
void strlower(char *s);
char *conf_strtok(char *str);
size_t pathjoin(char *dest, size_t destsize, const char *p1, const char *p2);
size_t stringjoin(char *dest, size_t destsize, ...);
int count_dir_elements(const char *p);
int clean_fname(char *name, int flags);
char *sanitize_path(char *dest, const char *p, const char *rootdir, int depth, int flags);
int change_dir(const char *dir, int set_path_only);
char *normalize_path(char *path, BOOL force_newbuf, unsigned int *len_ptr);
char *full_fname(const char *fn);
char *partial_dir_fname(const char *fname);
int handle_partial_dir(const char *fname, int create);
int unsafe_symlink(const char *dest, const char *src);
char *timestring(time_t t);
int same_time(time_t f1_sec, unsigned long f1_nsec, time_t f2_sec, unsigned long f2_nsec);
int _Insure_trap_error(int a1, int a2, int a3, int a4, int a5, int a6);
const char *find_filename_suffix(const char *fn, int fn_len, int *len_ptr);
uint32 fuzzy_distance(const char *s1, unsigned len1, const char *s2, unsigned len2);
struct bitbag *bitbag_create(int max_ndx);
void bitbag_set_bit(struct bitbag *bb, int ndx);
void bitbag_clear_bit(struct bitbag *bb, int ndx);
int bitbag_check_bit(struct bitbag *bb, int ndx);
int bitbag_next_bit(struct bitbag *bb, int after);
void flist_ndx_push(flist_ndx_list *lp, int ndx);
int flist_ndx_pop(flist_ndx_list *lp);
void *expand_item_list(item_list *lp, size_t item_size, const char *desc, int incr);
void force_memzero(void *buf, size_t len);
int msleep(int t);
void *my_alloc(void *ptr, size_t num, size_t size, const char *file, int line);
const char *sum_as_hex(int csum_type, const char *sum, int flist_csum);
NORETURN void _out_of_memory(const char *msg, const char *file, int line);
NORETURN void _overflow_exit(const char *msg, const char *file, int line);
const char *src_file(const char *file);
void free_xattr(stat_x *sxp);
int get_xattr(const char *fname, stat_x *sxp);
int copy_xattrs(const char *source, const char *dest);
int send_xattr(int f, stat_x *sxp);
int xattr_diff(struct file_struct *file, stat_x *sxp, int find_all);
void send_xattr_request(const char *fname, struct file_struct *file, int f_out);
int recv_xattr_request(struct file_struct *file, int f_in);
void receive_xattr(int f, struct file_struct *file);
void cache_tmp_xattr(struct file_struct *file, stat_x *sxp);
void uncache_tmp_xattrs(void);
int set_xattr(const char *fname, const struct file_struct *file, const char *fnamecmp, stat_x *sxp);
char *get_xattr_acl(const char *fname, int is_access_acl, size_t *len_p);
int set_xattr_acl(const char *fname, int is_access_acl, const char *buf, size_t buf_len);
int del_def_xattr_acl(const char *fname);
int get_stat_xattr(const char *fname, int fd, STRUCT_STAT *fst, STRUCT_STAT *xst);
int set_stat_xattr(const char *fname, struct file_struct *file, mode_t new_mode);
int x_stat(const char *fname, STRUCT_STAT *fst, STRUCT_STAT *xst);
int x_lstat(const char *fname, STRUCT_STAT *fst, STRUCT_STAT *xst);
int x_fstat(int fd, STRUCT_STAT *fst, STRUCT_STAT *xst);
char get_number_separator(void);
char get_decimal_point(void);
int sys_gettimeofday(struct timeval *tv);
char *do_big_num(int64 num, int human_flag, const char *fract);
char *do_big_dnum(double dnum, int human_flag, int decimal_digits);
char *lp_bind_address(void);
char *lp_daemon_chroot(void);
char *lp_daemon_gid(void);
char *lp_daemon_uid(void);
char *lp_motd_file(void);
char *lp_pid_file(void);
char *lp_socket_options(void);
int lp_listen_backlog(void);
int lp_rsync_port(void);
BOOL lp_proxy_protocol(void);
char *lp_auth_users(int module_id);
char *lp_charset(int module_id);
char *lp_comment(int module_id);
char *lp_dont_compress(int module_id);
char *lp_early_exec(int module_id);
char *lp_exclude(int module_id);
char *lp_exclude_from(int module_id);
char *lp_filter(int module_id);
char *lp_gid(int module_id);
char *lp_hosts_allow(int module_id);
char *lp_hosts_deny(int module_id);
char *lp_include(int module_id);
char *lp_include_from(int module_id);
char *lp_incoming_chmod(int module_id);
char *lp_lock_file(int module_id);
char *lp_log_file(int module_id);
char *lp_log_format(int module_id);
char *lp_name(int module_id);
char *lp_name_converter(int module_id);
char *lp_outgoing_chmod(int module_id);
char *lp_postxfer_exec(int module_id);
char *lp_prexfer_exec(int module_id);
char *lp_refuse_options(int module_id);
char *lp_secrets_file(int module_id);
char *lp_syslog_tag(int module_id);
char *lp_uid(int module_id);
char *lp_path(int module_id);
char *lp_temp_dir(int module_id);
int lp_max_connections(int module_id);
int lp_max_verbosity(int module_id);
int lp_timeout(int module_id);
int lp_syslog_facility(int module_id);
BOOL lp_fake_super(int module_id);
BOOL lp_forward_lookup(int module_id);
BOOL lp_ignore_errors(int module_id);
BOOL lp_ignore_nonreadable(int module_id);
BOOL lp_list(int module_id);
BOOL lp_read_only(int module_id);
BOOL lp_reverse_lookup(int module_id);
BOOL lp_strict_modes(int module_id);
BOOL lp_transfer_logging(int module_id);
BOOL lp_use_chroot(int module_id);
BOOL lp_write_only(int module_id);
BOOL lp_munge_symlinks(int module_id);
BOOL lp_numeric_ids(int module_id);
BOOL lp_open_noatime(int module_id);
