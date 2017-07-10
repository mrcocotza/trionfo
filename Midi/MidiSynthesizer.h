#ifndef MIDISYNTHESIZER_H
#define MIDISYNTHESIZER_H

#include <bass.h>
#include <bassmidi.h>
#include <vector>
#include <string>


class MidiSynthesizer
{
public:
    MidiSynthesizer();
    ~MidiSynthesizer();

    bool open();
    void close();

    bool setOutputDevice(int dv);
    void setSoundFonts(std::vector<std::string> &soundfonts);
    void setVolume(float vol);

    void sendNoteOff(int ch, int note, int velocity);
    void sendNoteOn(int ch, int note, int velocity);
    void sendNoteAftertouch(int ch, int note, int value);
    void sendController(int ch, int number, int value);
    void sendProgramChange(int ch, int number);
    void sendChannelAftertouch(int ch, int value);
    void sendPitchBend(int ch, int value);
    void sendAllNotesOff(int ch);
    void sendAllNotesOff();
    void sendResetAllControllers(int ch);
    void sendResetAllControllers();

private:
    HSTREAM stream;
    HSTREAM _bassDrum, _snareDrum, _tom1Drum, _tom2Drum;
    std::vector<HSOUNDFONT> synth_HSOUNDFONT;
    std::vector<BASS_MIDI_FONT> synth_BASS_MIDI_FONT;

    float synth_volume = 1.0f;
    bool openned = false;

    void setSfToStream();
};

#endif // MIDISYNTHESIZER_H
