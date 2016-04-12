/*************************************
 * @file    CommandRequest.h
 * @date    01/07/15
 * @author  Manuel
 *
 * Déclarations des classes définissant
 * les différentes requêtes émises par un client.
 *************************************
*/

#ifndef __COMMANDREQUEST_H__
#define __COMMANDREQUEST_H__

#include "Command.h"

class CommandRequest : public Command
{
    public:

        CommandRequest(Player::SongId songNum);
        virtual ~CommandRequest() {}

        virtual bool isRequest() const;

        virtual bool isReply() const;
};

class OpenCommandRequest : public CommandRequest
{
    public:

        OpenCommandRequest(Player::SongId songNum);
        virtual ~OpenCommandRequest() {}

        virtual char getCommandType() const;
};

class CloseCommandRequest : public CommandRequest
{
    public:

        CloseCommandRequest(Player::SongId songNum);
        virtual ~CloseCommandRequest() {}

        virtual char getCommandType() const;
};

class ReadCommandRequest : public CommandRequest
{
    private:

        unsigned int m_BytesToRead;

    public:

        ReadCommandRequest(Player::SongId songNum, unsigned int bytes);
        virtual ~ReadCommandRequest() {}

        virtual char getCommandType() const;

        virtual unsigned int getBytesToRead() const;

        virtual QByteArray toPacket() const;
};

class SeekCommandRequest : public CommandRequest
{
    private:

        unsigned int m_Pos;

    public:

        SeekCommandRequest(Player::SongId songNum, unsigned int pos);
        virtual ~SeekCommandRequest() {}

        virtual char getCommandType() const;

        virtual unsigned int getPos() const;

        virtual QByteArray toPacket() const;
};

#endif  // __COMMANDREQUEST_H__

