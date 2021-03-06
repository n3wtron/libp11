/*
 * Generated by util/mkerr.pl DO NOT EDIT
 * Copyright 1995-2017 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#include <stdio.h>
#include <openssl/err.h>
#include "p11_err.h"

#define P11_LIB_NAME "libp11"

/* BEGIN ERROR CODES */
#ifndef OPENSSL_NO_ERR

# define ERR_FUNC(func) ERR_PACK(0,func,0)
# define ERR_REASON(reason) ERR_PACK(0,0,reason)

static ERR_STRING_DATA P11_str_functs[] = {
    {ERR_FUNC(P11_F_PKCS11_CHANGE_PIN), "pkcs11_change_pin"},
    {ERR_FUNC(P11_F_PKCS11_CTX_LOAD), "pkcs11_CTX_load"},
    {ERR_FUNC(P11_F_PKCS11_CTX_RELOAD), "pkcs11_CTX_reload"},
    {ERR_FUNC(P11_F_PKCS11_ECDH_DERIVE), "pkcs11_ecdh_derive"},
    {ERR_FUNC(P11_F_PKCS11_GENERATE_KEY), "pkcs11_generate_key"},
    {ERR_FUNC(P11_F_PKCS11_GENERATE_RANDOM), "pkcs11_generate_random"},
    {ERR_FUNC(P11_F_PKCS11_INIT_PIN), "pkcs11_init_pin"},
    {ERR_FUNC(P11_F_PKCS11_LOGOUT), "pkcs11_logout"},
    {ERR_FUNC(P11_F_PKCS11_MECHANISM), "pkcs11_mechanism"},
    {ERR_FUNC(P11_F_PKCS11_SEED_RANDOM), "pkcs11_seed_random"},
    {ERR_FUNC(P11_F_PKCS11_STORE_KEY), "pkcs11_store_key"},
    {ERR_FUNC(P11_F_PKCS11_VERIFY), "PKCS11_verify"},
    {0, NULL}
};

static ERR_STRING_DATA P11_str_reasons[] = {
    {ERR_REASON(P11_R_KEYGEN_FAILED), "Key generation failed"},
    {ERR_REASON(P11_R_LOAD_MODULE_ERROR), "Unable to load PKCS#11 module"},
    {ERR_REASON(P11_R_NOT_SUPPORTED), "Not supported"},
    {ERR_REASON(P11_R_NO_SESSION), "No session open"},
    {ERR_REASON(P11_R_UI_FAILED), "UI request failed"},
    {ERR_REASON(P11_R_UNSUPPORTED_PADDING_TYPE), "Unsupported padding type"},
    {0, NULL}
};

#endif

#ifdef P11_LIB_NAME
static ERR_STRING_DATA P11_lib_name[] = {
    {0, P11_LIB_NAME},
    {0, NULL}
};
#endif

static int P11_lib_error_code = 0;
static int P11_error_init = 1;

int ERR_load_P11_strings(void)
{
    if (P11_lib_error_code == 0)
        P11_lib_error_code = ERR_get_next_error_library();

    if (P11_error_init) {
        P11_error_init = 0;
#ifndef OPENSSL_NO_ERR
        ERR_load_strings(P11_lib_error_code, P11_str_functs);
        ERR_load_strings(P11_lib_error_code, P11_str_reasons);
#endif

#ifdef P11_LIB_NAME
        P11_lib_name->error = ERR_PACK(P11_lib_error_code, 0, 0);
        ERR_load_strings(0, P11_lib_name);
#endif
    }
    return 1;
}

void ERR_unload_P11_strings(void)
{
    if (P11_error_init == 0) {
#ifndef OPENSSL_NO_ERR
        ERR_unload_strings(P11_lib_error_code, P11_str_functs);
        ERR_unload_strings(P11_lib_error_code, P11_str_reasons);
#endif

#ifdef P11_LIB_NAME
        ERR_unload_strings(0, P11_lib_name);
#endif
        P11_error_init = 1;
    }
}

void ERR_P11_error(int function, int reason, char *file, int line)
{
    if (P11_lib_error_code == 0)
        P11_lib_error_code = ERR_get_next_error_library();
    ERR_PUT_error(P11_lib_error_code, function, reason, file, line);
}
