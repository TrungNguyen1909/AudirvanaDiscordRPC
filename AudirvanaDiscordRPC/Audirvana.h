/*
 * Audirvana.h
 */

#import <AppKit/AppKit.h>


@class AudirvanaApplication;

enum AudirvanaPlayerStatus {
	AudirvanaPlayerStatusStopped = 1800426323 /* Playback Stopped */,
	AudirvanaPlayerStatusPlaying = 1800426320 /* Playing */,
	AudirvanaPlayerStatusPaused = 1800426352 /* Playback Paused */
};
typedef enum AudirvanaPlayerStatus AudirvanaPlayerStatus;

enum AudirvanaPlayerControlType {
	AudirvanaPlayerControlTypeLibrary = 'kCLb' /* Library mode, no external control */,
	AudirvanaPlayerControlTypeITunesIntegrated = 'kCiT' /* iTunes integrated mode, fully controlled by iTunes */
};
typedef enum AudirvanaPlayerControlType AudirvanaPlayerControlType;

enum AudirvanaPlayerStatusEventTypesReported {
	AudirvanaPlayerStatusEventTypesReportedNone = 'kEvN' /* No event reported/pushed */,
	AudirvanaPlayerStatusEventTypesReportedTrackChanged = 'kEvT' /* Tracks change, playback status pushed as events\nReported in notification com.audirvana.audirvana-plus.playerStatus with info dictionary containing:\nplayer status (Stopped, Playing, Paused) in key PlayerStatus\nPlaying track URL (if not stopped) in key PlayingTrackURL */,
	AudirvanaPlayerStatusEventTypesReportedTrackAndPosition = 'kEvP' /* Tracks, playback status, and play position (every second) pushed as events\nPlay position is reported in notification com.audirvana.audirvana-plus.playerPosition as a double (posInSec key) */
};
typedef enum AudirvanaPlayerStatusEventTypesReported AudirvanaPlayerStatusEventTypesReported;

enum AudirvanaTrackType {
	AudirvanaTrackTypeAudioFile = 'kTFl' /* Audio file, locally (file://) or http (http://) readable */,
	AudirvanaTrackTypeQobuzTrack = 'kTQB' /* Qobuz track, streamed from qobuz.com */,
	AudirvanaTrackTypeTidalTrack = 'kTTD' /* Tidal track, streamed from tidal.com */,
	AudirvanaTrackTypeHraTrack = 'kTHR' /* Qobuz track, streamed from highresaudio.com */
};
typedef enum AudirvanaTrackType AudirvanaTrackType;



/*
 * Audirvana Scripting Suite
 */

// Audirvana application class.
@interface AudirvanaApplication: NSObject

@property (readonly) NSNumber* playerState;  // Playback engine state (stopped, playing, ...)
@property AudirvanaPlayerControlType controlType;  // Player control type (standalone, by iTunes, by Apple Events)
@property AudirvanaPlayerStatusEventTypesReported eventTypesReported;  // Type of events (playback status, track change, player position within track (only in slave mode)) to be pushed
@property NSNumber* playerPosition;  // player position in the track in seconds
@property (copy, readonly) NSString *version;  // Version of Audirvana
@property (copy, readonly) NSString *playingTrackUrl;  // URL of currently playing track.
@property (copy, readonly) NSString *playingTrackTitle;  // Title of currently playing track.
@property (copy, readonly) NSString *playingTrackArtist;  // Artist of currently playing track.
@property (copy, readonly) NSString *playingTrackAlbum;  // Album of currently playing track.
@property (readonly) NSNumber* playingTrackDuration;  // Duration of currently playing track.
@property (copy, readonly) NSData *playingTrackAirfoillogo;  // Logo for the currently playing track.

- (void) playpause;  // Start playback, toggle play pause mode
- (void) stop;  // Stop playback
- (void) pause;  // Pause playback
- (void) resume;  // Resume playback
- (void) nextTrack;  // Seek to next track
- (void) previousTrack;  // Seek to previous track
- (void) backTrack;  // move to beginning of the track, or go to previous track if already at beginning
- (void) setPlayingTrackType:(AudirvanaTrackType)type URL:(NSString *)URL trackID:(NSInteger)trackID;  // set/change playing track (in slave mode). trackID is optional and needed only for Qobuz tracks
- (void) setNextTrackType:(AudirvanaTrackType)type URL:(NSString *)URL trackID:(NSInteger)trackID;  // set/change track to be played after current one (in slave mode). trackID is optional and needed only for Qobuz tracks

@end

