// Copyright 2020-2023 Bloomberg Finance L.P.
// SPDX-License-Identifier: Apache-2.0
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <ntca_getdomainnamecontext.h>

#include <bsls_ident.h>
BSLS_IDENT_RCSID(ntca_getdomainnamecontext_cpp, "$Id$ $CSID$")

#include <bslim_printer.h>

namespace BloombergLP {
namespace ntca {

bool GetDomainNameContext::equals(const GetDomainNameContext& other) const
{
    return (d_ipAddress == other.d_ipAddress && d_latency == other.d_latency &&
            d_source == other.d_source && d_nameServer == other.d_nameServer &&
            d_timeToLive == other.d_timeToLive && d_error == other.d_error);
}

bool GetDomainNameContext::less(const GetDomainNameContext& other) const
{
    if (d_ipAddress < other.d_ipAddress) {
        return true;
    }

    if (other.d_ipAddress < d_ipAddress) {
        return false;
    }

    if (d_latency < other.d_latency) {
        return true;
    }

    if (d_latency > other.d_latency) {
        return false;
    }

    if (d_source < other.d_source) {
        return true;
    }

    if (d_source > other.d_source) {
        return false;
    }

    if (d_nameServer < other.d_nameServer) {
        return true;
    }

    if (other.d_nameServer < d_nameServer) {
        return false;
    }

    if (d_timeToLive < other.d_timeToLive) {
        return true;
    }

    if (d_timeToLive > other.d_timeToLive) {
        return false;
    }

    return d_error < other.d_error;
}

bsl::ostream& GetDomainNameContext::print(bsl::ostream& stream,
                                          int           level,
                                          int           spacesPerLevel) const
{
    bslim::Printer printer(&stream, level, spacesPerLevel);
    printer.start();
    printer.printAttribute("ipAddress", d_ipAddress);
    printer.printAttribute("latency", d_latency);
    printer.printAttribute("source", d_source);
    printer.printAttribute("nameServer", d_nameServer);
    printer.printAttribute("timeToLive", d_timeToLive);
    printer.printAttribute("error", d_error);
    printer.end();
    return stream;
}

}  // close package namespace
}  // close enterprise namespace