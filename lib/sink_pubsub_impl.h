/* -*- c++ -*- */
/* 
 * Copyright 2013 Institute for Theoretical Information Technology,
 *                RWTH Aachen University
 * 
 * Authors: Johannes Schmitz <schmitz@ti.rwth-aachen.de>
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_ZMQBLOCKS_SINK_PUBSUB_IMPL_H
#define INCLUDED_ZMQBLOCKS_SINK_PUBSUB_IMPL_H

#include <zmqblocks/sink_pubsub.h>
#include "zmq.hpp"

namespace gr {
  namespace zmqblocks {

    class sink_pubsub_impl : public sink_pubsub
    {
    private:
        size_t          d_itemsize;
        zmq::context_t  *d_context;
        zmq::socket_t   *d_socket;

     public:
        sink_pubsub_impl(size_t itemsize, char *address);
        ~sink_pubsub_impl();

        int work(int noutput_items,
                 gr_vector_const_void_star &input_items,
                 gr_vector_void_star &output_items);
		virtual void byebye();
    };

  } // namespace zmqblocks
} // namespace gr

#endif /* INCLUDED_ZMQBLOCKS_SINK_PUBSUB_IMPL_H */

