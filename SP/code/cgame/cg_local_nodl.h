extern void	cg_trap_Print( const char *fmt );
#define trap_Print cg_trap_Print
extern void	cg_trap_Error(const char *fmt) __attribute__((noreturn));
#define trap_Error cg_trap_Error
extern void        cg_trap_Endgame( void );
#define trap_Endgame cg_trap_Endgame
extern int         cg_trap_Milliseconds( void );
#define trap_Milliseconds cg_trap_Milliseconds
extern void        cg_trap_Cvar_Register( vmCvar_t *vmCvar, const char *varName, const char *defaultValue, int flags );
#define trap_Cvar_Register cg_trap_Cvar_Register
extern void        cg_trap_Cvar_Update( vmCvar_t *vmCvar );
#define trap_Cvar_Update cg_trap_Cvar_Update
extern void        cg_trap_Cvar_Set( const char *var_name, const char *value );
#define trap_Cvar_Set cg_trap_Cvar_Set
extern void        cg_trap_Cvar_VariableStringBuffer( const char *var_name, char *buffer, int bufsize );
#define trap_Cvar_VariableStringBuffer cg_trap_Cvar_VariableStringBuffer
extern int         cg_trap_Argc( void );
#define trap_Argc cg_trap_Argc
extern void        cg_trap_Argv( int n, char *buffer, int bufferLength );
#define trap_Argv cg_trap_Argv
extern void        cg_trap_Args( char *buffer, int bufferLength );
#define trap_Args cg_trap_Args
extern int         cg_trap_FS_FOpenFile( const char *qpath, fileHandle_t *f, fsMode_t mode );
#define trap_FS_FOpenFile cg_trap_FS_FOpenFile
extern void        cg_trap_FS_Read( void *buffer, int len, fileHandle_t f );
#define trap_FS_Read cg_trap_FS_Read
extern void        cg_trap_FS_Write( const void *buffer, int len, fileHandle_t f );
#define trap_FS_Write cg_trap_FS_Write
extern void        cg_trap_FS_FCloseFile( fileHandle_t f );
#define trap_FS_FCloseFile cg_trap_FS_FCloseFile
extern void        cg_trap_FS_CopyFile( char *from, char *to );
#define trap_FS_CopyFile cg_trap_FS_CopyFile
extern void        cg_trap_SendConsoleCommand( const char *text );
#define trap_SendConsoleCommand cg_trap_SendConsoleCommand
extern void	cg_trap_AddCommand( const char *cmdName );
#define trap_AddCommand cg_trap_AddCommand
extern void	cg_trap_RemoveCommand( const char *cmdName );
#define trap_RemoveCommand cg_trap_RemoveCommand
extern void        cg_trap_SendClientCommand( const char *s );
#define trap_SendClientCommand cg_trap_SendClientCommand
extern void        cg_trap_UpdateScreen( void );
#define trap_UpdateScreen cg_trap_UpdateScreen
extern void        cg_trap_CM_LoadMap( const char *mapname );
#define trap_CM_LoadMap cg_trap_CM_LoadMap
extern int         cg_trap_CM_NumInlineModels( void );
#define trap_CM_NumInlineModels cg_trap_CM_NumInlineModels
extern clipHandle_t cg_trap_CM_InlineModel( int index );
#define trap_CM_InlineModel cg_trap_CM_InlineModel
extern clipHandle_t cg_trap_CM_TempBoxModel( const vec3_t mins, const vec3_t maxs );
#define trap_CM_TempBoxModel cg_trap_CM_TempBoxModel
extern clipHandle_t cg_trap_CM_TempCapsuleModel( const vec3_t mins, const vec3_t maxs );
#define trap_CM_TempCapsuleModel cg_trap_CM_TempCapsuleModel
extern int         cg_trap_CM_PointContents( const vec3_t p, clipHandle_t model );
#define trap_CM_PointContents cg_trap_CM_PointContents
extern int         cg_trap_CM_TransformedPointContents( const vec3_t p, clipHandle_t model, const vec3_t origin, const vec3_t angles );
#define trap_CM_TransformedPointContents cg_trap_CM_TransformedPointContents
extern void        cg_trap_CM_BoxTrace( trace_t *results, const vec3_t start, const vec3_t end,
                                        const vec3_t mins, const vec3_t maxs,
                                        clipHandle_t model, int brushmask );
#define trap_CM_BoxTrace cg_trap_CM_BoxTrace
extern void        cg_trap_CM_TransformedBoxTrace( trace_t *results, const vec3_t start, const vec3_t end,
                                                   const vec3_t mins, const vec3_t maxs,
                                                   clipHandle_t model, int brushmask,
                                                   const vec3_t origin, const vec3_t angles );
#define trap_CM_TransformedBoxTrace cg_trap_CM_TransformedBoxTrace
extern void        cg_trap_CM_CapsuleTrace( trace_t *results, const vec3_t start, const vec3_t end,
                                            const vec3_t mins, const vec3_t maxs,
                                            clipHandle_t model, int brushmask );
#define trap_CM_CapsuleTrace cg_trap_CM_CapsuleTrace
extern void        cg_trap_CM_TransformedCapsuleTrace( trace_t *results, const vec3_t start, const vec3_t end,
                                                       const vec3_t mins, const vec3_t maxs,
                                                       clipHandle_t model, int brushmask,
                                                       const vec3_t origin, const vec3_t angles );
#define trap_CM_TransformedCapsuleTrace cg_trap_CM_TransformedCapsuleTrace
extern int         cg_trap_CM_MarkFragments( int numPoints, const vec3_t *points,
                                             const vec3_t projection,
                                             int maxPoints, vec3_t pointBuffer,
                                             int maxFragments, markFragment_t *fragmentBuffer );
#define trap_CM_MarkFragments cg_trap_CM_MarkFragments
extern void        cg_trap_S_StartSound( vec3_t origin, int entityNum, int entchannel, sfxHandle_t sfx );
#define trap_S_StartSound cg_trap_S_StartSound
extern void        cg_trap_S_StartSoundEx( vec3_t origin, int entityNum, int entchannel, sfxHandle_t sfx, int flags );
#define trap_S_StartSoundEx cg_trap_S_StartSoundEx
extern void        cg_trap_S_StopLoopingSound( int entnum );
#define trap_S_StopLoopingSound cg_trap_S_StopLoopingSound
extern void        cg_trap_S_StopStreamingSound( int entnum );
#define trap_S_StopStreamingSound cg_trap_S_StopStreamingSound
extern void        cg_trap_S_StartLocalSound( sfxHandle_t sfx, int channelNum );
#define trap_S_StartLocalSound cg_trap_S_StartLocalSound
extern void        cg_trap_S_ClearLoopingSounds( qboolean killall );
#define trap_S_ClearLoopingSounds cg_trap_S_ClearLoopingSounds
extern void        cg_trap_S_AddLoopingSound( int entityNum, const vec3_t origin, const vec3_t velocity, int range, sfxHandle_t sfx, int volume );
#define trap_S_AddLoopingSound cg_trap_S_AddLoopingSound
extern void        cg_trap_S_UpdateEntityPosition( int entityNum, const vec3_t origin );
#define trap_S_UpdateEntityPosition cg_trap_S_UpdateEntityPosition
extern int         cg_trap_S_GetVoiceAmplitude( int entityNum );
#define trap_S_GetVoiceAmplitude cg_trap_S_GetVoiceAmplitude
extern void cg_trap_S_Respatialize( int entityNum, const vec3_t origin, vec3_t axis[3], int inwater );
#define trap_S_Respatialize cg_trap_S_Respatialize
extern sfxHandle_t cg_trap_S_RegisterSound( const char *sample );
#define trap_S_RegisterSound cg_trap_S_RegisterSound
extern void        cg_trap_S_StartBackgroundTrack( const char *intro, const char *loop, int fadeupTime );
#define trap_S_StartBackgroundTrack cg_trap_S_StartBackgroundTrack
extern void        cg_trap_S_StopBackgroundTrack( void );
#define trap_S_StopBackgroundTrack cg_trap_S_StopBackgroundTrack
extern void        cg_trap_S_FadeBackgroundTrack( float targetvol, int time, int sound );
#define trap_S_FadeBackgroundTrack cg_trap_S_FadeBackgroundTrack
extern void        cg_trap_S_StartStreamingSound( const char *intro, const char *loop, int entnum, int channel, int attenuation );
#define trap_S_StartStreamingSound cg_trap_S_StartStreamingSound
extern void        cg_trap_S_FadeAllSound( float targetvol, int time );
#define trap_S_FadeAllSound cg_trap_S_FadeAllSound
extern void        cg_trap_R_LoadWorldMap( const char *mapname );
#define trap_R_LoadWorldMap cg_trap_R_LoadWorldMap
extern qhandle_t   cg_trap_R_RegisterModel( const char *name );
#define trap_R_RegisterModel cg_trap_R_RegisterModel
extern qhandle_t   cg_trap_R_RegisterSkin( const char *name );
#define trap_R_RegisterSkin cg_trap_R_RegisterSkin
extern qhandle_t   cg_trap_R_RegisterShader( const char *name );
#define trap_R_RegisterShader cg_trap_R_RegisterShader
extern qhandle_t   cg_trap_R_RegisterShaderNoMip( const char *name );
#define trap_R_RegisterShaderNoMip cg_trap_R_RegisterShaderNoMip
extern qboolean    cg_trap_R_GetSkinModel( qhandle_t skinid, const char *type, char *name );
#define trap_R_GetSkinModel cg_trap_R_GetSkinModel
extern qhandle_t   cg_trap_R_GetShaderFromModel( qhandle_t modelid, int surfnum, int withlightmap );
#define trap_R_GetShaderFromModel cg_trap_R_GetShaderFromModel
extern void        cg_trap_R_ClearScene( void );
#define trap_R_ClearScene cg_trap_R_ClearScene
extern void        cg_trap_R_AddRefEntityToScene( const refEntity_t *re );
#define trap_R_AddRefEntityToScene cg_trap_R_AddRefEntityToScene
extern void        cg_trap_R_AddPolyToScene( qhandle_t hShader, int numVerts, const polyVert_t *verts );
#define trap_R_AddPolyToScene cg_trap_R_AddPolyToScene
extern void        cg_trap_R_AddPolysToScene( qhandle_t hShader, int numVerts, const polyVert_t *verts, int numPolys );
#define trap_R_AddPolysToScene cg_trap_R_AddPolysToScene
extern void        cg_trap_RB_ZombieFXAddNewHit( int entityNum, const vec3_t hitPos, const vec3_t hitDir );
#define trap_RB_ZombieFXAddNewHit cg_trap_RB_ZombieFXAddNewHit
extern void        cg_trap_R_AddLightToScene( const vec3_t org, float intensity, float r, float g, float b, int overdraw );
#define trap_R_AddLightToScene cg_trap_R_AddLightToScene
extern void	    cg_trap_R_AddAdditiveLightToScene( const vec3_t org, float intensity, float r, float g, float b );
#define trap_R_AddAdditiveLightToScene cg_trap_R_AddAdditiveLightToScene
extern void        cg_trap_R_AddCoronaToScene( const vec3_t org, float r, float g, float b, float scale, int id, int flags );
#define trap_R_AddCoronaToScene cg_trap_R_AddCoronaToScene
extern void        cg_trap_R_RenderScene( const refdef_t *fd );
#define trap_R_RenderScene cg_trap_R_RenderScene
extern void        cg_trap_R_SetColor( const float *rgba );
#define trap_R_SetColor cg_trap_R_SetColor
extern void        cg_trap_R_DrawStretchPic( float x, float y, float w, float h,
                                             float s1, float t1, float s2, float t2, qhandle_t hShader );
#define trap_R_DrawStretchPic cg_trap_R_DrawStretchPic
extern void        cg_trap_R_DrawStretchPicGradient( float x, float y, float w, float h,
                                                     float s1, float t1, float s2, float t2, qhandle_t hShader, const float *gradientColor, int gradientType );
#define trap_R_DrawStretchPicGradient cg_trap_R_DrawStretchPicGradient
extern void        cg_trap_R_ModelBounds( clipHandle_t model, vec3_t mins, vec3_t maxs );
#define trap_R_ModelBounds cg_trap_R_ModelBounds
extern int         cg_trap_R_LerpTag( orientation_t *tag, const refEntity_t *refent, const char *tagName, int startIndex );
#define trap_R_LerpTag cg_trap_R_LerpTag
extern void        cg_trap_R_RemapShader( const char *oldShader, const char *newShader, const char *timeOffset );
#define trap_R_RemapShader cg_trap_R_RemapShader
extern qboolean    cg_trap_R_inPVS( const vec3_t p1, const vec3_t p2 );
#define trap_R_inPVS cg_trap_R_inPVS
extern void    cg_trap_R_SetFog( int fogvar, int var1, int var2, float r, float g, float b, float density );
#define trap_R_SetFog cg_trap_R_SetFog
extern void        cg_trap_GetGlconfig( glconfig_t *glconfig );
#define trap_GetGlconfig cg_trap_GetGlconfig
extern void        cg_trap_GetGameState( gameState_t *gamestate );
#define trap_GetGameState cg_trap_GetGameState
extern void        cg_trap_GetCurrentSnapshotNumber( int *snapshotNumber, int *serverTime );
#define trap_GetCurrentSnapshotNumber cg_trap_GetCurrentSnapshotNumber
extern qboolean    cg_trap_GetSnapshot( int snapshotNumber, snapshot_t *snapshot );
#define trap_GetSnapshot cg_trap_GetSnapshot
extern qboolean    cg_trap_GetServerCommand( int serverCommandNumber );
#define trap_GetServerCommand cg_trap_GetServerCommand
extern int         cg_trap_GetCurrentCmdNumber( void );
#define trap_GetCurrentCmdNumber cg_trap_GetCurrentCmdNumber
extern qboolean    cg_trap_GetUserCmd( int cmdNumber, usercmd_t *ucmd );
#define trap_GetUserCmd cg_trap_GetUserCmd
extern void        cg_trap_SetUserCmdValue( int stateValue, int holdValue, float sensitivityScale, int cld );
#define trap_SetUserCmdValue cg_trap_SetUserCmdValue
extern int         cg_trap_MemoryRemaining( void );
#define trap_MemoryRemaining cg_trap_MemoryRemaining
extern void        cg_trap_R_RegisterFont( const char *fontName, int pointSize, fontInfo_t *font );
#define trap_R_RegisterFont cg_trap_R_RegisterFont
extern qboolean    cg_trap_Key_IsDown( int keynum );
#define trap_Key_IsDown cg_trap_Key_IsDown
extern int         cg_trap_Key_GetCatcher( void );
#define trap_Key_GetCatcher cg_trap_Key_GetCatcher
extern void        cg_trap_Key_SetCatcher( int catcher );
#define trap_Key_SetCatcher cg_trap_Key_SetCatcher
extern int         cg_trap_Key_GetKey( const char *binding );
#define trap_Key_GetKey cg_trap_Key_GetKey
extern void cg_trap_SendMoveSpeedsToGame( int entnum, char *movespeeds );
#define trap_SendMoveSpeedsToGame cg_trap_SendMoveSpeedsToGame
extern void cg_trap_UI_Popup( const char *arg0 );
#define trap_UI_Popup cg_trap_UI_Popup
extern void cg_trap_UI_ClosePopup( const char *arg0 );
#define trap_UI_ClosePopup cg_trap_UI_ClosePopup
extern void cg_trap_UI_LimboChat( const char *arg0 );
#define trap_UI_LimboChat cg_trap_UI_LimboChat
extern int cg_trap_CIN_PlayCinematic( const char *arg0, int xpos, int ypos, int width, int height, int bits );
#define trap_CIN_PlayCinematic cg_trap_CIN_PlayCinematic
extern e_status cg_trap_CIN_StopCinematic( int handle );
#define trap_CIN_StopCinematic cg_trap_CIN_StopCinematic
extern e_status cg_trap_CIN_RunCinematic( int handle );
#define trap_CIN_RunCinematic cg_trap_CIN_RunCinematic
extern void cg_trap_CIN_DrawCinematic( int handle );
#define trap_CIN_DrawCinematic cg_trap_CIN_DrawCinematic
extern void cg_trap_CIN_SetExtents( int handle, int x, int y, int w, int h );
#define trap_CIN_SetExtents cg_trap_CIN_SetExtents
extern int	cg_trap_RealTime(qtime_t *qtime);
#define trap_RealTime cg_trap_RealTime
extern void cg_trap_SnapVector( float *v );
#define trap_SnapVector cg_trap_SnapVector
extern qboolean    cg_trap_GetEntityToken( char *buffer, int bufferSize );
#define trap_GetEntityToken cg_trap_GetEntityToken
extern qboolean    cg_trap_loadCamera( int camNum, const char *name );
#define trap_loadCamera cg_trap_loadCamera
extern void        cg_trap_startCamera( int camNum, int time );
#define trap_startCamera cg_trap_startCamera
extern void        cg_trap_stopCamera( int camNum );
#define trap_stopCamera cg_trap_stopCamera
extern qboolean    cg_trap_getCameraInfo( int camNum, int time, vec3_t *origin, vec3_t *angles, float *fov );
#define trap_getCameraInfo cg_trap_getCameraInfo
extern qboolean    cg_trap_GetModelInfo( int clientNum, char *modelName, animModelInfo_t **modelInfo );
#define trap_GetModelInfo cg_trap_GetModelInfo
extern void		*cg_trap_Alloc( int size );
#define trap_Alloc cg_trap_Alloc
extern int cg_trap_PC_LoadSource( const char *filename );
#define trap_PC_LoadSource cg_trap_PC_LoadSource
extern int cg_trap_PC_ReadToken( int handle, pc_token_t *pc_token );
#define trap_PC_ReadToken cg_trap_PC_ReadToken