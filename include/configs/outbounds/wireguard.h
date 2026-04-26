#pragma once
#include "include/configs/common/Outbound.h"

namespace Configs
{
    class Peer : public baseConfig
    {
        public:
        QString address;
        int port = 0;
        QString public_key;
        QString pre_shared_key;
        QList<int> reserved;
        int persistent_keepalive = 0;

        // baseConfig overrides
        bool ParseFromLink(const QString& link) override;
        bool ParseFromJson(const QJsonObject& object) override;
        QString ExportToLink() override;
        QJsonObject ExportToJson() override;
        BuildResult Build() override;
    };

    class wireguard : public outbound
    {
        public:
        QString private_key;
        std::shared_ptr<Peer> peer = std::make_shared<Peer>();
        QStringList address;
        int mtu = 1420;
        bool system = false;
        int worker_count = 0;
        QString udp_timeout;

        // AmneziaWG
        bool amneziawg = false;
        int Jc = 0;
        int Jmin = 64;
        int Jmax = 1024;
        int S1 = 0;
        int S2 = 0;
        int S3 = 0;
        int S4 = 0;
        int H1_min = 0;
        int H1_max = 0;
        int H2_min = 0;
        int H2_max = 0;
        int H3_min = 0;
        int H3_max = 0;
        int H4_min = 0;
        int H4_max = 0;
        QString I1;
        QString I2;
        QString I3;
        QString I4;
        QString I5;

        // baseConfig overrides
        bool ParseFromLink(const QString& link) override;
        bool ParseFromJson(const QJsonObject& object) override;
        QString ExportToLink() override;
        QJsonObject ExportToJson() override;
        BuildResult Build() override;

        void SetPort(int newPort) override;
        QString GetPort() override;
        void SetAddress(QString newAddr) override;
        QString GetAddress() override;
        QString DisplayAddress() override;
        QString DisplayType() override;
        bool IsEndpoint() override;
    };
}


