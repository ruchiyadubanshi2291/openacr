//
// include/gen/atf_norm_gen.h
// Generated by AMC
//
// (C) AlgoEngineering LLC 2008-2013
// (C) NYSE | Intercontinental Exchange 2013-2016
//


#pragma once
#include "include/gen/command_gen.h"
#include "include/gen/atfdb_gen.h"
#include "include/gen/algo_gen.h"
#include "include/gen/dmmeta_gen.h"
#include "include/gen/dev_gen.h"
//#pragma endinclude

// --- atf_norm_FieldIdEnum

enum atf_norm_FieldIdEnum {        // atf_norm.FieldId.value
     atf_norm_FieldId_value   = 0
};

enum { atf_norm_FieldIdEnum_N = 1 };


// --- atf_norm_TableIdEnum

enum atf_norm_TableIdEnum {                   // atf_norm.TableId.value
     atf_norm_TableId_dmmeta_Ns         = 0   // dmmeta.Ns -> atf_norm.FNs
    ,atf_norm_TableId_dmmeta_ns         = 0   // dmmeta.ns -> atf_norm.FNs
    ,atf_norm_TableId_dev_Readme        = 1   // dev.Readme -> atf_norm.FReadme
    ,atf_norm_TableId_dev_readme        = 1   // dev.readme -> atf_norm.FReadme
    ,atf_norm_TableId_dev_Scriptfile    = 2   // dev.Scriptfile -> atf_norm.FScriptfile
    ,atf_norm_TableId_dev_scriptfile    = 2   // dev.scriptfile -> atf_norm.FScriptfile
    ,atf_norm_TableId_dmmeta_Ssimfile   = 3   // dmmeta.Ssimfile -> atf_norm.FSsimfile
    ,atf_norm_TableId_dmmeta_ssimfile   = 3   // dmmeta.ssimfile -> atf_norm.FSsimfile
};

enum { atf_norm_TableIdEnum_N = 8 };

namespace atfdb { struct Normcheck; }
namespace dmmeta { struct Ns; }
namespace dev { struct Readme; }
namespace dev { struct Scriptfile; }
namespace dmmeta { struct Ssimfile; }
namespace atf_norm { struct trace; }
namespace atf_norm { struct FDb; }
namespace atf_norm { struct FNormcheck; }
namespace atf_norm { struct FNs; }
namespace atf_norm { struct FReadme; }
namespace atf_norm { struct FScriptfile; }
namespace atf_norm { struct FSsimfile; }
namespace atf_norm { struct FieldId; }
namespace atf_norm { struct TableId; }
namespace atf_norm { struct _db_normcheck_curs; }
namespace atf_norm { struct _db_ssimfile_curs; }
namespace atf_norm { struct _db_ind_ssimfile_curs; }
namespace atf_norm { struct _db_scriptfile_curs; }
namespace atf_norm { struct _db_ind_scriptfile_curs; }
namespace atf_norm { struct _db_ns_curs; }
namespace atf_norm { struct _db_ind_ns_curs; }
namespace atf_norm { struct _db_readme_curs; }
namespace atf_norm {
}//pkey typedefs
namespace atf_norm {
extern const char *atf_norm_help;
extern const char *atf_norm_syntax;
extern FDb _db;
typedef void (*normcheck_step_hook)();

// --- atf_norm.trace
#pragma pack(push,1)
struct trace { // atf_norm.trace
    trace();
};
#pragma pack(pop)

// print string representation of atf_norm::trace to string LHS, no header -- cprint:atf_norm.trace.String
void                 trace_Print(atf_norm::trace & row, algo::cstring &str) __attribute__((nothrow));

// --- atf_norm.FDb
// create: atf_norm.FDb._db (Global)
struct FDb { // atf_norm.FDb
    command::atf_norm         cmdline;                        //
    atf_norm::FNormcheck*     normcheck_lary[32];             // level array
    i32                       normcheck_n;                    // number of elements in array
    atf_norm::FSsimfile*      ssimfile_lary[32];              // level array
    i32                       ssimfile_n;                     // number of elements in array
    atf_norm::FSsimfile**     ind_ssimfile_buckets_elems;     // pointer to bucket array
    i32                       ind_ssimfile_buckets_n;         // number of elements in bucket array
    i32                       ind_ssimfile_n;                 // number of elements in the hash table
    atf_norm::FNormcheck*     c_normcheck;                    // optional pointer
    bool                      env_loaded;                     //   false
    atf_norm::FScriptfile*    scriptfile_lary[32];            // level array
    i32                       scriptfile_n;                   // number of elements in array
    atf_norm::FScriptfile**   ind_scriptfile_buckets_elems;   // pointer to bucket array
    i32                       ind_scriptfile_buckets_n;       // number of elements in bucket array
    i32                       ind_scriptfile_n;               // number of elements in the hash table
    atf_norm::FNs*            ns_lary[32];                    // level array
    i32                       ns_n;                           // number of elements in array
    atf_norm::FNs**           ind_ns_buckets_elems;           // pointer to bucket array
    i32                       ind_ns_buckets_n;               // number of elements in bucket array
    i32                       ind_ns_n;                       // number of elements in the hash table
    atf_norm::FReadme*        readme_lary[32];                // level array
    i32                       readme_n;                       // number of elements in array
    atf_norm::trace           trace;                          //
};

// Main function
void                 MainArgs(int argc, char **argv);
// Main loop.
void                 MainLoop();
// Main step
void                 Step();
// Main function
void                 Main();
void                 StaticCheck();
// Parse strptr into known type and add to database.
// Return value is true unless an error occurs. If return value is false, algo_lib::_db.errtext has error text
bool                 InsertStrptrMaybe(algo::strptr str);
// Load all finputs from given directory.
bool                 LoadTuplesMaybe(algo::strptr root) __attribute__((nothrow));
// Load specified ssimfile.
bool                 LoadSsimfileMaybe(algo::strptr fname) __attribute__((nothrow));
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Call Unref or Delete to cleanup partially inserted row.
bool                 _db_XrefMaybe();

// Allocate memory for new default row.
// If out of memory, process is killed.
atf_norm::FNormcheck& normcheck_Alloc() __attribute__((__warn_unused_result__, nothrow));
// Allocate memory for new element. If out of memory, return NULL.
atf_norm::FNormcheck* normcheck_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
// Create new row from struct.
// Return pointer to new element, or NULL if insertion failed (due to out-of-memory, duplicate key, etc)
atf_norm::FNormcheck* normcheck_InsertMaybe(const atfdb::Normcheck &value) __attribute__((nothrow));
// Allocate space for one element. If no memory available, return NULL.
void*                normcheck_AllocMem() __attribute__((__warn_unused_result__, nothrow));
// Return true if index is empty
bool                 normcheck_EmptyQ() __attribute__((nothrow));
// Look up row by row id. Return NULL if out of range
atf_norm::FNormcheck* normcheck_Find(u64 t) __attribute__((__warn_unused_result__, nothrow));
// Return pointer to last element of array, or NULL if array is empty
atf_norm::FNormcheck* normcheck_Last() __attribute__((nothrow, pure));
// Return number of items in the pool
i32                  normcheck_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Remove all elements from Lary
void                 normcheck_RemoveAll() __attribute__((nothrow));
// Delete last element of array. Do nothing if array is empty.
void                 normcheck_RemoveLast() __attribute__((nothrow));
// 'quick' Access row by row id. No bounds checking.
atf_norm::FNormcheck& normcheck_qFind(u64 t) __attribute__((nothrow));
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Call Unref or Delete to cleanup partially inserted row.
bool                 normcheck_XrefMaybe(atf_norm::FNormcheck &row);

// Allocate memory for new default row.
// If out of memory, process is killed.
atf_norm::FSsimfile& ssimfile_Alloc() __attribute__((__warn_unused_result__, nothrow));
// Allocate memory for new element. If out of memory, return NULL.
atf_norm::FSsimfile* ssimfile_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
// Create new row from struct.
// Return pointer to new element, or NULL if insertion failed (due to out-of-memory, duplicate key, etc)
atf_norm::FSsimfile* ssimfile_InsertMaybe(const dmmeta::Ssimfile &value) __attribute__((nothrow));
// Allocate space for one element. If no memory available, return NULL.
void*                ssimfile_AllocMem() __attribute__((__warn_unused_result__, nothrow));
// Return true if index is empty
bool                 ssimfile_EmptyQ() __attribute__((nothrow));
// Look up row by row id. Return NULL if out of range
atf_norm::FSsimfile* ssimfile_Find(u64 t) __attribute__((__warn_unused_result__, nothrow));
// Return pointer to last element of array, or NULL if array is empty
atf_norm::FSsimfile* ssimfile_Last() __attribute__((nothrow, pure));
// Return number of items in the pool
i32                  ssimfile_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Delete last element of array. Do nothing if array is empty.
void                 ssimfile_RemoveLast() __attribute__((nothrow));
// 'quick' Access row by row id. No bounds checking.
atf_norm::FSsimfile& ssimfile_qFind(u64 t) __attribute__((nothrow));
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Call Unref or Delete to cleanup partially inserted row.
bool                 ssimfile_XrefMaybe(atf_norm::FSsimfile &row);

// Return true if hash is empty
bool                 ind_ssimfile_EmptyQ() __attribute__((nothrow));
// Find row by key. Return NULL if not found.
atf_norm::FSsimfile* ind_ssimfile_Find(const algo::strptr& key) __attribute__((__warn_unused_result__, nothrow));
// Look up row by key and return reference. Throw exception if not found
atf_norm::FSsimfile& ind_ssimfile_FindX(const algo::strptr& key);
// Find row by key. If not found, create and x-reference a new row with with this key.
atf_norm::FSsimfile& ind_ssimfile_GetOrCreate(const algo::strptr& key) __attribute__((nothrow));
// Return number of items in the hash
i32                  ind_ssimfile_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Insert row into hash table. Return true if row is reachable through the hash after the function completes.
bool                 ind_ssimfile_InsertMaybe(atf_norm::FSsimfile& row) __attribute__((nothrow));
// Remove reference to element from hash index. If element is not in hash, do nothing
void                 ind_ssimfile_Remove(atf_norm::FSsimfile& row) __attribute__((nothrow));
// Reserve enough room in the hash for N more elements. Return success code.
void                 ind_ssimfile_Reserve(int n) __attribute__((nothrow));

// Allocate memory for new default row.
// If out of memory, process is killed.
atf_norm::FScriptfile& scriptfile_Alloc() __attribute__((__warn_unused_result__, nothrow));
// Allocate memory for new element. If out of memory, return NULL.
atf_norm::FScriptfile* scriptfile_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
// Create new row from struct.
// Return pointer to new element, or NULL if insertion failed (due to out-of-memory, duplicate key, etc)
atf_norm::FScriptfile* scriptfile_InsertMaybe(const dev::Scriptfile &value) __attribute__((nothrow));
// Allocate space for one element. If no memory available, return NULL.
void*                scriptfile_AllocMem() __attribute__((__warn_unused_result__, nothrow));
// Return true if index is empty
bool                 scriptfile_EmptyQ() __attribute__((nothrow));
// Look up row by row id. Return NULL if out of range
atf_norm::FScriptfile* scriptfile_Find(u64 t) __attribute__((__warn_unused_result__, nothrow));
// Return pointer to last element of array, or NULL if array is empty
atf_norm::FScriptfile* scriptfile_Last() __attribute__((nothrow, pure));
// Return number of items in the pool
i32                  scriptfile_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Remove all elements from Lary
void                 scriptfile_RemoveAll() __attribute__((nothrow));
// Delete last element of array. Do nothing if array is empty.
void                 scriptfile_RemoveLast() __attribute__((nothrow));
// 'quick' Access row by row id. No bounds checking.
atf_norm::FScriptfile& scriptfile_qFind(u64 t) __attribute__((nothrow));
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Call Unref or Delete to cleanup partially inserted row.
bool                 scriptfile_XrefMaybe(atf_norm::FScriptfile &row);

// Return true if hash is empty
bool                 ind_scriptfile_EmptyQ() __attribute__((nothrow));
// Find row by key. Return NULL if not found.
atf_norm::FScriptfile* ind_scriptfile_Find(const algo::strptr& key) __attribute__((__warn_unused_result__, nothrow));
// Look up row by key and return reference. Throw exception if not found
atf_norm::FScriptfile& ind_scriptfile_FindX(const algo::strptr& key);
// Find row by key. If not found, create and x-reference a new row with with this key.
atf_norm::FScriptfile& ind_scriptfile_GetOrCreate(const algo::strptr& key) __attribute__((nothrow));
// Return number of items in the hash
i32                  ind_scriptfile_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Insert row into hash table. Return true if row is reachable through the hash after the function completes.
bool                 ind_scriptfile_InsertMaybe(atf_norm::FScriptfile& row) __attribute__((nothrow));
// Remove reference to element from hash index. If element is not in hash, do nothing
void                 ind_scriptfile_Remove(atf_norm::FScriptfile& row) __attribute__((nothrow));
// Reserve enough room in the hash for N more elements. Return success code.
void                 ind_scriptfile_Reserve(int n) __attribute__((nothrow));

// Allocate memory for new default row.
// If out of memory, process is killed.
atf_norm::FNs&       ns_Alloc() __attribute__((__warn_unused_result__, nothrow));
// Allocate memory for new element. If out of memory, return NULL.
atf_norm::FNs*       ns_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
// Create new row from struct.
// Return pointer to new element, or NULL if insertion failed (due to out-of-memory, duplicate key, etc)
atf_norm::FNs*       ns_InsertMaybe(const dmmeta::Ns &value) __attribute__((nothrow));
// Allocate space for one element. If no memory available, return NULL.
void*                ns_AllocMem() __attribute__((__warn_unused_result__, nothrow));
// Return true if index is empty
bool                 ns_EmptyQ() __attribute__((nothrow));
// Look up row by row id. Return NULL if out of range
atf_norm::FNs*       ns_Find(u64 t) __attribute__((__warn_unused_result__, nothrow));
// Return pointer to last element of array, or NULL if array is empty
atf_norm::FNs*       ns_Last() __attribute__((nothrow, pure));
// Return number of items in the pool
i32                  ns_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Remove all elements from Lary
void                 ns_RemoveAll() __attribute__((nothrow));
// Delete last element of array. Do nothing if array is empty.
void                 ns_RemoveLast() __attribute__((nothrow));
// 'quick' Access row by row id. No bounds checking.
atf_norm::FNs&       ns_qFind(u64 t) __attribute__((nothrow));
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Call Unref or Delete to cleanup partially inserted row.
bool                 ns_XrefMaybe(atf_norm::FNs &row);

// Return true if hash is empty
bool                 ind_ns_EmptyQ() __attribute__((nothrow));
// Find row by key. Return NULL if not found.
atf_norm::FNs*       ind_ns_Find(const algo::strptr& key) __attribute__((__warn_unused_result__, nothrow));
// Look up row by key and return reference. Throw exception if not found
atf_norm::FNs&       ind_ns_FindX(const algo::strptr& key);
// Find row by key. If not found, create and x-reference a new row with with this key.
atf_norm::FNs&       ind_ns_GetOrCreate(const algo::strptr& key) __attribute__((nothrow));
// Return number of items in the hash
i32                  ind_ns_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Insert row into hash table. Return true if row is reachable through the hash after the function completes.
bool                 ind_ns_InsertMaybe(atf_norm::FNs& row) __attribute__((nothrow));
// Remove reference to element from hash index. If element is not in hash, do nothing
void                 ind_ns_Remove(atf_norm::FNs& row) __attribute__((nothrow));
// Reserve enough room in the hash for N more elements. Return success code.
void                 ind_ns_Reserve(int n) __attribute__((nothrow));

// Allocate memory for new default row.
// If out of memory, process is killed.
atf_norm::FReadme&   readme_Alloc() __attribute__((__warn_unused_result__, nothrow));
// Allocate memory for new element. If out of memory, return NULL.
atf_norm::FReadme*   readme_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
// Create new row from struct.
// Return pointer to new element, or NULL if insertion failed (due to out-of-memory, duplicate key, etc)
atf_norm::FReadme*   readme_InsertMaybe(const dev::Readme &value) __attribute__((nothrow));
// Allocate space for one element. If no memory available, return NULL.
void*                readme_AllocMem() __attribute__((__warn_unused_result__, nothrow));
// Return true if index is empty
bool                 readme_EmptyQ() __attribute__((nothrow));
// Look up row by row id. Return NULL if out of range
atf_norm::FReadme*   readme_Find(u64 t) __attribute__((__warn_unused_result__, nothrow));
// Return pointer to last element of array, or NULL if array is empty
atf_norm::FReadme*   readme_Last() __attribute__((nothrow, pure));
// Return number of items in the pool
i32                  readme_N() __attribute__((__warn_unused_result__, nothrow, pure));
// Remove all elements from Lary
void                 readme_RemoveAll() __attribute__((nothrow));
// Delete last element of array. Do nothing if array is empty.
void                 readme_RemoveLast() __attribute__((nothrow));
// 'quick' Access row by row id. No bounds checking.
atf_norm::FReadme&   readme_qFind(u64 t) __attribute__((nothrow));
// Insert row into all appropriate indices. If error occurs, store error
// in algo_lib::_db.errtext and return false. Call Unref or Delete to cleanup partially inserted row.
bool                 readme_XrefMaybe(atf_norm::FReadme &row);

// cursor points to valid item
void                 _db_normcheck_curs_Reset(_db_normcheck_curs &curs, atf_norm::FDb &parent);
// cursor points to valid item
bool                 _db_normcheck_curs_ValidQ(_db_normcheck_curs &curs);
// proceed to next item
void                 _db_normcheck_curs_Next(_db_normcheck_curs &curs);
// item access
atf_norm::FNormcheck& _db_normcheck_curs_Access(_db_normcheck_curs &curs);
// cursor points to valid item
void                 _db_ssimfile_curs_Reset(_db_ssimfile_curs &curs, atf_norm::FDb &parent);
// cursor points to valid item
bool                 _db_ssimfile_curs_ValidQ(_db_ssimfile_curs &curs);
// proceed to next item
void                 _db_ssimfile_curs_Next(_db_ssimfile_curs &curs);
// item access
atf_norm::FSsimfile& _db_ssimfile_curs_Access(_db_ssimfile_curs &curs);
// cursor points to valid item
void                 _db_scriptfile_curs_Reset(_db_scriptfile_curs &curs, atf_norm::FDb &parent);
// cursor points to valid item
bool                 _db_scriptfile_curs_ValidQ(_db_scriptfile_curs &curs);
// proceed to next item
void                 _db_scriptfile_curs_Next(_db_scriptfile_curs &curs);
// item access
atf_norm::FScriptfile& _db_scriptfile_curs_Access(_db_scriptfile_curs &curs);
// cursor points to valid item
void                 _db_ns_curs_Reset(_db_ns_curs &curs, atf_norm::FDb &parent);
// cursor points to valid item
bool                 _db_ns_curs_ValidQ(_db_ns_curs &curs);
// proceed to next item
void                 _db_ns_curs_Next(_db_ns_curs &curs);
// item access
atf_norm::FNs&       _db_ns_curs_Access(_db_ns_curs &curs);
// cursor points to valid item
void                 _db_readme_curs_Reset(_db_readme_curs &curs, atf_norm::FDb &parent);
// cursor points to valid item
bool                 _db_readme_curs_ValidQ(_db_readme_curs &curs);
// proceed to next item
void                 _db_readme_curs_Next(_db_readme_curs &curs);
// item access
atf_norm::FReadme&   _db_readme_curs_Access(_db_readme_curs &curs);
// Set all fields to initial values.
void                 FDb_Init();
void                 FDb_Uninit() __attribute__((nothrow));

// --- atf_norm.FNormcheck
// create: atf_norm.FDb.normcheck (Lary)
// global access: c_normcheck (Ptr)
struct FNormcheck { // atf_norm.FNormcheck
    algo::Smallstr50                normcheck;   //
    algo::Comment                   comment;     //
    i32                             nerr;        //   0
    atf_norm::normcheck_step_hook   step;        //   NULL  Pointer to a function
private:
    friend atf_norm::FNormcheck& normcheck_Alloc() __attribute__((__warn_unused_result__, nothrow));
    friend atf_norm::FNormcheck* normcheck_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
    friend void                 normcheck_RemoveAll() __attribute__((nothrow));
    friend void                 normcheck_RemoveLast() __attribute__((nothrow));
    FNormcheck();
    // reftype of atf_norm.FNormcheck.step prohibits copy
    FNormcheck(const FNormcheck&){ /*disallow copy constructor */}
    void operator =(const FNormcheck&){ /*disallow direct assignment */}
};

// Copy fields out of row
void                 normcheck_CopyOut(atf_norm::FNormcheck &row, atfdb::Normcheck &out) __attribute__((nothrow));
// Copy fields in to row
void                 normcheck_CopyIn(atf_norm::FNormcheck &row, atfdb::Normcheck &in) __attribute__((nothrow));

// Invoke function by pointer
void                 step_Call(atf_norm::FNormcheck& normcheck) __attribute__((nothrow));

// Set all fields to initial values.
void                 FNormcheck_Init(atf_norm::FNormcheck& normcheck);

// --- atf_norm.FNs
// create: atf_norm.FDb.ns (Lary)
// global access: ind_ns (Thash)
struct FNs { // atf_norm.FNs
    atf_norm::FNs*     ind_ns_next;   // hash next
    algo::Smallstr16   ns;            // Namespace name (primary key)
    algo::Smallstr50   nstype;        //
    algo::Comment      comment;       //
private:
    friend atf_norm::FNs&       ns_Alloc() __attribute__((__warn_unused_result__, nothrow));
    friend atf_norm::FNs*       ns_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
    friend void                 ns_RemoveAll() __attribute__((nothrow));
    friend void                 ns_RemoveLast() __attribute__((nothrow));
    FNs();
    ~FNs();
    FNs(const FNs&){ /*disallow copy constructor */}
    void operator =(const FNs&){ /*disallow direct assignment */}
};

// Copy fields out of row
void                 ns_CopyOut(atf_norm::FNs &row, dmmeta::Ns &out) __attribute__((nothrow));
// Copy fields in to row
void                 ns_CopyIn(atf_norm::FNs &row, dmmeta::Ns &in) __attribute__((nothrow));

// Set all fields to initial values.
void                 FNs_Init(atf_norm::FNs& ns);
void                 FNs_Uninit(atf_norm::FNs& ns) __attribute__((nothrow));

// --- atf_norm.FReadme
// create: atf_norm.FDb.readme (Lary)
struct FReadme { // atf_norm.FReadme
    algo::Smallstr200   gitfile;   //
    algo::Comment       comment;   //
private:
    friend atf_norm::FReadme&   readme_Alloc() __attribute__((__warn_unused_result__, nothrow));
    friend atf_norm::FReadme*   readme_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
    friend void                 readme_RemoveAll() __attribute__((nothrow));
    friend void                 readme_RemoveLast() __attribute__((nothrow));
    FReadme();
};

// Copy fields out of row
void                 readme_CopyOut(atf_norm::FReadme &row, dev::Readme &out) __attribute__((nothrow));
// Copy fields in to row
void                 readme_CopyIn(atf_norm::FReadme &row, dev::Readme &in) __attribute__((nothrow));


// --- atf_norm.FScriptfile
// create: atf_norm.FDb.scriptfile (Lary)
// global access: ind_scriptfile (Thash)
struct FScriptfile { // atf_norm.FScriptfile
    atf_norm::FScriptfile*   ind_scriptfile_next;   // hash next
    algo::Smallstr200        gitfile;               //
    algo::Smallstr100        args;                  //
    algo::Comment            comment;               //
private:
    friend atf_norm::FScriptfile& scriptfile_Alloc() __attribute__((__warn_unused_result__, nothrow));
    friend atf_norm::FScriptfile* scriptfile_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
    friend void                 scriptfile_RemoveAll() __attribute__((nothrow));
    friend void                 scriptfile_RemoveLast() __attribute__((nothrow));
    FScriptfile();
    ~FScriptfile();
    FScriptfile(const FScriptfile&){ /*disallow copy constructor */}
    void operator =(const FScriptfile&){ /*disallow direct assignment */}
};

// Copy fields out of row
void                 scriptfile_CopyOut(atf_norm::FScriptfile &row, dev::Scriptfile &out) __attribute__((nothrow));
// Copy fields in to row
void                 scriptfile_CopyIn(atf_norm::FScriptfile &row, dev::Scriptfile &in) __attribute__((nothrow));

// Set all fields to initial values.
void                 FScriptfile_Init(atf_norm::FScriptfile& scriptfile);
void                 FScriptfile_Uninit(atf_norm::FScriptfile& scriptfile) __attribute__((nothrow));

// --- atf_norm.FSsimfile
// create: atf_norm.FDb.ssimfile (Lary)
// global access: ind_ssimfile (Thash)
struct FSsimfile { // atf_norm.FSsimfile
    atf_norm::FSsimfile*   ind_ssimfile_next;   // hash next
    algo::Smallstr50       ssimfile;            //
    algo::Smallstr50       ctype;               //
private:
    friend atf_norm::FSsimfile& ssimfile_Alloc() __attribute__((__warn_unused_result__, nothrow));
    friend atf_norm::FSsimfile* ssimfile_AllocMaybe() __attribute__((__warn_unused_result__, nothrow));
    friend void                 ssimfile_RemoveLast() __attribute__((nothrow));
    FSsimfile();
    ~FSsimfile();
    FSsimfile(const FSsimfile&){ /*disallow copy constructor */}
    void operator =(const FSsimfile&){ /*disallow direct assignment */}
};

// Copy fields out of row
void                 ssimfile_CopyOut(atf_norm::FSsimfile &row, dmmeta::Ssimfile &out) __attribute__((nothrow));
// Copy fields in to row
void                 ssimfile_CopyIn(atf_norm::FSsimfile &row, dmmeta::Ssimfile &in) __attribute__((nothrow));

algo::Smallstr16     ssimns_Get(atf_norm::FSsimfile& ssimfile) __attribute__((__warn_unused_result__, nothrow));

algo::Smallstr16     ns_Get(atf_norm::FSsimfile& ssimfile) __attribute__((__warn_unused_result__, nothrow));

algo::Smallstr50     name_Get(atf_norm::FSsimfile& ssimfile) __attribute__((__warn_unused_result__, nothrow));

// Set all fields to initial values.
void                 FSsimfile_Init(atf_norm::FSsimfile& ssimfile);
void                 FSsimfile_Uninit(atf_norm::FSsimfile& ssimfile) __attribute__((nothrow));

// --- atf_norm.FieldId
#pragma pack(push,1)
struct FieldId { // atf_norm.FieldId: Field read helper
    i32   value;   //   -1
    inline operator atf_norm_FieldIdEnum() const;
    explicit FieldId(i32                            in_value);
    FieldId(atf_norm_FieldIdEnum arg);
    FieldId();
};
#pragma pack(pop)

// Get value of field as enum type
atf_norm_FieldIdEnum value_GetEnum(const atf_norm::FieldId& parent) __attribute__((nothrow));
// Set value of field from enum type.
void                 value_SetEnum(atf_norm::FieldId& parent, atf_norm_FieldIdEnum rhs) __attribute__((nothrow));
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
const char*          value_ToCstr(const atf_norm::FieldId& parent) __attribute__((nothrow));
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
void                 value_Print(const atf_norm::FieldId& parent, algo::cstring &lhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
bool                 value_SetStrptrMaybe(atf_norm::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
void                 value_SetStrptr(atf_norm::FieldId& parent, algo::strptr rhs, atf_norm_FieldIdEnum dflt) __attribute__((nothrow));
// Convert string to field. Return success value
bool                 value_ReadStrptrMaybe(atf_norm::FieldId& parent, algo::strptr rhs) __attribute__((nothrow));

// Read fields of atf_norm::FieldId from an ascii string.
// The format of the string is the format of the atf_norm::FieldId's only field
bool                 FieldId_ReadStrptrMaybe(atf_norm::FieldId &parent, algo::strptr in_str);
// Set all fields to initial values.
void                 FieldId_Init(atf_norm::FieldId& parent);
// print string representation of atf_norm::FieldId to string LHS, no header -- cprint:atf_norm.FieldId.String
void                 FieldId_Print(atf_norm::FieldId & row, algo::cstring &str) __attribute__((nothrow));

// --- atf_norm.TableId
struct TableId { // atf_norm.TableId: Index of table in this namespace
    i32   value;   //   -1  index of table
    inline operator atf_norm_TableIdEnum() const;
    explicit TableId(i32                            in_value);
    TableId(atf_norm_TableIdEnum arg);
    TableId();
};

// Get value of field as enum type
atf_norm_TableIdEnum value_GetEnum(const atf_norm::TableId& parent) __attribute__((nothrow));
// Set value of field from enum type.
void                 value_SetEnum(atf_norm::TableId& parent, atf_norm_TableIdEnum rhs) __attribute__((nothrow));
// Convert numeric value of field to one of predefined string constants.
// If string is found, return a static C string. Otherwise, return NULL.
const char*          value_ToCstr(const atf_norm::TableId& parent) __attribute__((nothrow));
// Convert value to a string. First, attempt conversion to a known string.
// If no string matches, print value as a numeric value.
void                 value_Print(const atf_norm::TableId& parent, algo::cstring &lhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, do not modify field and return false.
// In case of success, return true
bool                 value_SetStrptrMaybe(atf_norm::TableId& parent, algo::strptr rhs) __attribute__((nothrow));
// Convert string to field.
// If the string is invalid, set numeric value to DFLT
void                 value_SetStrptr(atf_norm::TableId& parent, algo::strptr rhs, atf_norm_TableIdEnum dflt) __attribute__((nothrow));
// Convert string to field. Return success value
bool                 value_ReadStrptrMaybe(atf_norm::TableId& parent, algo::strptr rhs) __attribute__((nothrow));

// Read fields of atf_norm::TableId from an ascii string.
// The format of the string is the format of the atf_norm::TableId's only field
bool                 TableId_ReadStrptrMaybe(atf_norm::TableId &parent, algo::strptr in_str);
// Set all fields to initial values.
void                 TableId_Init(atf_norm::TableId& parent);
// print string representation of atf_norm::TableId to string LHS, no header -- cprint:atf_norm.TableId.String
void                 TableId_Print(atf_norm::TableId & row, algo::cstring &str) __attribute__((nothrow));

struct _db_normcheck_curs {// cursor
    typedef atf_norm::FNormcheck ChildType;
    atf_norm::FDb *parent;
    i64 index;
    _db_normcheck_curs(){ parent=NULL; index=0; }
};


struct _db_ssimfile_curs {// cursor
    typedef atf_norm::FSsimfile ChildType;
    atf_norm::FDb *parent;
    i64 index;
    _db_ssimfile_curs(){ parent=NULL; index=0; }
};


struct _db_scriptfile_curs {// cursor
    typedef atf_norm::FScriptfile ChildType;
    atf_norm::FDb *parent;
    i64 index;
    _db_scriptfile_curs(){ parent=NULL; index=0; }
};


struct _db_ns_curs {// cursor
    typedef atf_norm::FNs ChildType;
    atf_norm::FDb *parent;
    i64 index;
    _db_ns_curs(){ parent=NULL; index=0; }
};


struct _db_readme_curs {// cursor
    typedef atf_norm::FReadme ChildType;
    atf_norm::FDb *parent;
    i64 index;
    _db_readme_curs(){ parent=NULL; index=0; }
};

// User-implemented function from gstatic:atf_norm.FDb.normcheck
void                 normcheck_amc();
// User-implemented function from gstatic:atf_norm.FDb.normcheck
void                 normcheck_testamc();
// User-implemented function from gstatic:atf_norm.FDb.normcheck
void                 normcheck_readme();
// User-implemented function from gstatic:atf_norm.FDb.normcheck
void                 normcheck_unit();
// User-implemented function from gstatic:atf_norm.FDb.normcheck
void                 normcheck_copyright();
// User-implemented function from gstatic:atf_norm.FDb.normcheck
void                 normcheck_iffy_src();
// User-implemented function from gstatic:atf_norm.FDb.normcheck
void                 normcheck_stray_gen();
// User-implemented function from gstatic:atf_norm.FDb.normcheck
void                 normcheck_tempcode();
// User-implemented function from gstatic:atf_norm.FDb.normcheck
void                 normcheck_gitfile();
// User-implemented function from gstatic:atf_norm.FDb.normcheck
void                 normcheck_indent_srcfile();
// User-implemented function from gstatic:atf_norm.FDb.normcheck
void                 normcheck_indent_script();
// User-implemented function from gstatic:atf_norm.FDb.normcheck
void                 normcheck_normalize_amc_vis();
// User-implemented function from gstatic:atf_norm.FDb.normcheck
void                 normcheck_src_lim();
// User-implemented function from gstatic:atf_norm.FDb.normcheck
void                 normcheck_ssimfile();
// User-implemented function from gstatic:atf_norm.FDb.normcheck
void                 normcheck_normalize_acr();
// User-implemented function from gstatic:atf_norm.FDb.normcheck
void                 normcheck_normalize_acr_my();
// User-implemented function from gstatic:atf_norm.FDb.normcheck
void                 normcheck_bootstrap();
int                  main(int argc, char **argv);
} // end namespace atf_norm
namespace algo {
inline algo::cstring &operator <<(algo::cstring &str, const atf_norm::trace &row);// cfmt:atf_norm.trace.String
inline algo::cstring &operator <<(algo::cstring &str, const atf_norm::FieldId &row);// cfmt:atf_norm.FieldId.String
inline algo::cstring &operator <<(algo::cstring &str, const atf_norm::TableId &row);// cfmt:atf_norm.TableId.String
}