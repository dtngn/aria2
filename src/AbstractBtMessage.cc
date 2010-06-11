/* <!-- copyright */
/*
 * aria2 - The high speed download utility
 *
 * Copyright (C) 2006 Tatsuhiro Tsujikawa
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *
 * In addition, as a special exception, the copyright holders give
 * permission to link the code of portions of this program with the
 * OpenSSL library under certain conditions as described in each
 * individual source file, and distribute linked combinations
 * including the two.
 * You must obey the GNU General Public License in all respects
 * for all of the code used other than OpenSSL.  If you modify
 * file(s) with this exception, you may extend this exception to your
 * version of the file(s), but you are not obligated to do so.  If you
 * do not wish to do so, delete this exception statement from your
 * version.  If you delete this exception statement from all source
 * files in the program, then also delete it here.
 */
/* copyright --> */
#include "AbstractBtMessage.h"
#include "Peer.h"
#include "PieceStorage.h"
#include "BtMessageValidator.h"
#include "LogFactory.h"
#include "Logger.h"

namespace aria2 {

AbstractBtMessage::AbstractBtMessage(uint8_t id, const std::string& name):
  BtMessage(id),
  _sendingInProgress(false),
  _invalidate(false),
  _uploading(false),
  _cuid(0),
  _name(name),
  _metadataGetMode(false),
  _logger(LogFactory::getInstance())
{}

AbstractBtMessage::~AbstractBtMessage() {}

void AbstractBtMessage::setPeer(const SharedHandle<Peer>& peer)
{
  _peer = peer;
}

void AbstractBtMessage::validate()
{
  if(!_validator.isNull()) {
    _validator->validate();
  }
}

void
AbstractBtMessage::setBtMessageValidator(const SharedHandle<BtMessageValidator>& validator) {
  _validator = validator;
}

void AbstractBtMessage::setPieceStorage
(const SharedHandle<PieceStorage>& pieceStorage)
{
  _pieceStorage = pieceStorage;
}

void AbstractBtMessage::setBtMessageDispatcher
(const WeakHandle<BtMessageDispatcher>& dispatcher)
{
  _dispatcher = dispatcher;
}

void AbstractBtMessage::setPeerConnection(const WeakHandle<PeerConnection>& peerConnection)
{
  _peerConnection = peerConnection;
}

void AbstractBtMessage::setBtMessageFactory(const WeakHandle<BtMessageFactory>& factory)
{
  _messageFactory = factory;
}

void AbstractBtMessage::setBtRequestFactory(const WeakHandle<BtRequestFactory>& factory)
{
  _requestFactory = factory;
}

} // namespace aria2
