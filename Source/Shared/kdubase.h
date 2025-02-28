/*******************************************************************************
*
*  (C) COPYRIGHT AUTHORS, 2022
*
*  TITLE:       KDUBASE.H
*
*  VERSION:     1.27
*
*  DATE:        10 Nov 2022
*
*  Base KDU definitions.
*
* THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
* ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED
* TO THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
* PARTICULAR PURPOSE.
*
*******************************************************************************/

#pragma once

#pragma warning(disable: 4201)

typedef enum _KDU_SOURCEBASE {
    SourceBaseNone = 0,
    SourceBaseWinIo,
    SourceBaseWinRing0,
    SourceBasePhyMem,
    SourceBaseMapMem,
    SourceBaseRWEverything,
    SourceBaseMax
} KDU_SOURCEBASE;

typedef struct _KDU_DB_ENTRY {
    ULONG MinNtBuildNumberSupport;
    ULONG MaxNtBuildNumberSupport;
    ULONG ResourceId;
    ULONG ProviderId;
    KDU_SOURCEBASE DrvSourceBase;
    union {
        ULONG Flags;
        struct {
            ULONG SupportHVCI : 1;
            ULONG SignatureWHQL : 1;
            ULONG IgnoreChecksum : 1;
            ULONG NoForcedSD : 1;
            ULONG NoUnloadSupported : 1;
            ULONG PML4FromLowStub : 1;
            ULONG NoVictim : 1;
            ULONG PhysMemoryBruteForce : 1;
            ULONG Reserved : 24;
        };
    };
    ULONG SupportedShellFlags;
    LPWSTR Desciption;
    LPWSTR DriverName; //only file name, e.g. PROCEXP
    LPWSTR DeviceName; //device name, e.g. PROCEXP152
    LPWSTR SignerName;
} KDU_DB_ENTRY, * PKDU_DB_ENTRY;

typedef struct _KDU_DB {
    ULONG NumberOfEntries;
    KDU_DB_ENTRY* Entries;
} KDU_DB, * PKDU_DB;
