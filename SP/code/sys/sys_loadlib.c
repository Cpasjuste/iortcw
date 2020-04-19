#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include "ui_local.h"

// ui
int handle_ui = 0x1;

extern void
dllEntry(intptr_t (QDECL *syscallptr)(intptr_t arg, ...));

extern intptr_t
vmMain(intptr_t command, intptr_t arg0, intptr_t arg1, intptr_t arg2, intptr_t arg3, intptr_t arg4, intptr_t arg5,
       intptr_t arg6, intptr_t arg7, intptr_t arg8, intptr_t arg9, intptr_t arg10, intptr_t arg11);

// game
int handle_game = 0x2;

extern void
g_dllEntry(intptr_t (QDECL *syscallptr)(intptr_t arg, ...));

extern intptr_t
g_vmMain(intptr_t command, intptr_t arg0, intptr_t arg1, intptr_t arg2, intptr_t arg3, intptr_t arg4, intptr_t arg5,
         intptr_t arg6, intptr_t arg7, intptr_t arg8, intptr_t arg9, intptr_t arg10, intptr_t arg11);

// cgame
int handle_cgame = 0x3;

extern void
cg_dllEntry(intptr_t (QDECL *syscallptr)(intptr_t arg, ...));

extern intptr_t
cg_vmMain(intptr_t command, intptr_t arg0, intptr_t arg1, intptr_t arg2, intptr_t arg3, intptr_t arg4, intptr_t arg5,
          intptr_t arg6, intptr_t arg7, intptr_t arg8, intptr_t arg9, intptr_t arg10, intptr_t arg11);

void *NODL_LoadObject(const char *sofile) {
    printf("NODL_LoadObject(%s)\n", sofile);
    if (strcmp(sofile, "ui.so") == 0) {
        return &handle_ui;
    } else if (strcmp(sofile, "qagame.so") == 0) {
        return &handle_game;
    } else if (strcmp(sofile, "cgame.so") == 0) {
        return &handle_cgame;
    }
}

void NODL_UnloadObject(void *handle) {

    if (handle == &handle_ui) {
        printf("NODL_UnloadObject: ui\n");
    } else if (handle == &handle_game) {
        printf("NODL_UnloadObject: game\n");
    } else if (handle == &handle_cgame) {
        printf("NODL_UnloadObject: cgame\n");
    } else {
        printf("NODL_UnloadObject: unknown\n");
    }
}

void *NODL_LoadFunction(void *handle, const char *name) {
    printf("NODL_LoadFunction(%p, %s)\n", handle, name);
    if (handle == &handle_ui) {
        if (strcmp(name, "dllEntry") == 0) {
            printf("NODL_LoadFunction: ui::dllEntry\n");
            return dllEntry;
        } else if (strcmp(name, "vmMain") == 0) {
            printf("NODL_LoadFunction: ui::vmMain\n");
            return vmMain;
        } else {
            printf("NODL_LoadFunction: ui:: not implemented\n");
        }
    } else if (handle == &handle_game) {
        if (strcmp(name, "dllEntry") == 0) {
            printf("NODL_LoadFunction: game::dllEntry\n");
            return g_dllEntry;
        } else if (strcmp(name, "vmMain") == 0) {
            printf("NODL_LoadFunction: game::vmMain\n");
            return g_vmMain;
        } else {
            printf("NODL_LoadFunction: game:: not implemented\n");
        }
    } else if (handle == &handle_cgame) {
        if (strcmp(name, "dllEntry") == 0) {
            printf("NODL_LoadFunction: cgame::dllEntry\n");
            return cg_dllEntry;
        } else if (strcmp(name, "vmMain") == 0) {
            printf("NODL_LoadFunction: cgame::vmMain\n");
            return cg_vmMain;
        } else {
            printf("NODL_LoadFunction: cgame:: not implemented\n");
        }
    }

    return NULL;
}
