/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * main.cc
 * Copyright (C) 2017 andrew kralovec <andrew@root>
 * 
 * gstreamer is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * gstreamer is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <gstreamermm.h>
#include <glibmm.h>
#include <iostream>
#include <stdlib.h>
#include <gstreamermm/playbin.h>
#include <string>

Glib::RefPtr<Glib::MainLoop> mainloop;
Glib::RefPtr<Gst::Pipeline> pipeline;
Glib::RefPtr<Gst::Element> element_source, element_filter, element_sink;
Glib::RefPtr<Gst::Bus> bus;
Glib::RefPtr<Gst::Message> msg;

void print(std::string message); 

int main(int argc, char** argv)
{
	// Initialize Gstreamermm:
	Gst::init(argc, argv);

	// Create pipeline:
	pipeline = Gst::Pipeline::create("pipeline");

	// Create elements:
	element_source = Gst::ElementFactory::create_element("fakesrc");
	element_filter = Gst::ElementFactory::create_element("identity");
	element_sink = Gst::ElementFactory::create_element("fakesink");

	// We must add the elements to the pipeline before linking them:
	try
	{
		pipeline->add(element_source)->add(element_filter)->add(element_sink);
	}
	catch (const std::runtime_error& ex)
	{
		std::cerr << "Exception while adding: " << ex.what() << std::endl;
		return 1;
	}

	// Link the elements together:
	try
	{
		element_source->link(element_filter)->link(element_sink);
	}
	catch(const std::runtime_error& error)
	{
		std::cerr << "Exception while linking: " << error.what() << std::endl;
		return 1;
	}
	print("Start Playing"); 

	return 0;
}
void print(std::string message){
  std::cout << message << std::endl;
}




